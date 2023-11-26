// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainGamePlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "CPP_PlayerPawn.h"
#include "Engine.h"
#include "CPP_GameCameraActor.h"
#include "Kismet/GameplayStatics.h"

void ACPP_MainGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	//MouseYが入力されたらバインドした関数を呼ぶように登録
	GetMutableDefault<UInputSettings>()->AddAxisMapping(FInputAxisKeyMapping("Player_MovePitch", EKeys::MouseY, 1.0f));//ここでアンリアルエンジンに操作方法を登録
	InputComponent->BindAxis("Player_MovePitch", this, &ACPP_MainGamePlayerController::AddPitchInput);//ここで登録した操作方法に関数をバインド

	//左マウスボタンが押されたらバインドした関数を呼ぶように登録
	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Fire", EKeys::LeftMouseButton));//ここでアンリアルエンジンに操作方法を登録
	InputComponent->BindAction("Player_Fire", IE_Pressed, this, &ACPP_MainGamePlayerController::Fire);//ここで登録した操作方法に関数をバインド
}

//"Player_MovePitch"入力に反応する関数
void ACPP_MainGamePlayerController::AddPitchInput(float Val)
{
	Super::AddPitchInput(Val);
	ACPP_PlayerPawn* PossessedPawn = Cast<ACPP_PlayerPawn>(GetPawn());
	if (PossessedPawn != nullptr)
	{
		PossessedPawn->MouseMovePitchInput(Val);
	}
}

void ACPP_MainGamePlayerController::Fire()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Fire1"));
	ACPP_PlayerPawn* PossessedPawn = Cast<ACPP_PlayerPawn>(GetPawn());
	if (PossessedPawn != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Fire2"));
		PossessedPawn->Fire();
	}
}

void ACPP_MainGamePlayerController::BeginPlay()
{
	TArray<AActor*> FindedActors;
	UGameplayStatics::GetAllActorsOfClass(this, ACPP_GameCameraActor::StaticClass(), FindedActors);

	for (AActor* Actor : FindedActors)
	{
		ACPP_GameCameraActor* Camera = Cast<ACPP_GameCameraActor>(Actor);
		if (Camera != nullptr)
		{
			GameCameras.Add(Camera);
		}
	}

	//Super::BeginPlayは最後に呼んでおく（Blueprintの処理が先に行われる？を参照）
	Super::BeginPlay();
}