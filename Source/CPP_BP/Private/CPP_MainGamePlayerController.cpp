// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainGamePlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "CPP_PlayerPawn.h"
#include "Engine.h"
#include "CPP_GameCameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "CPP_PauseMenuWidget.h"

ACPP_MainGamePlayerController::ACPP_MainGamePlayerController() : Super()
{
	static ConstructorHelpers::FClassFinder<UCPP_PauseMenuWidget> PauseMenuClass(TEXT("/Game/WBP_PauseMenu"));
	if (PauseMenuClass.Succeeded())
	{
		PauseMenuWidgetClass = PauseMenuClass.Class;
	}
}

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

	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Pause", EKeys::P));
	InputComponent->BindAction("Player_Pause", IE_Pressed, this, &ACPP_MainGamePlayerController::OnPauseMenu);
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

	if (PauseMenuWidgetClass != nullptr)
	{
		PauseMenuWidget = CreateWidget<UCPP_PauseMenuWidget>(this, PauseMenuWidgetClass);
	}

	//Super::BeginPlayは最後に呼んでおく（Blueprintの処理が先に行われる？を参照）
	Super::BeginPlay();
}

ACPP_GameCameraActor* ACPP_MainGamePlayerController::ChangeGameCamera(const FName& Tag)
{
	for (ACPP_GameCameraActor* Camera : GameCameras)//foreach
	{
		if (Camera != nullptr)
		{
			if (Camera->ActorHasTag(Tag))
			{
				//切り替えたいカメラを発見
				SetViewTargetWithBlend(Cast<AActor>(Camera));
				return Camera;
			}
		}
	}

	return Cast<ACPP_GameCameraActor>(GetViewTarget());
}

void ACPP_MainGamePlayerController::OnPauseMenu()
{
	if (PauseMenuWidget != nullptr)
	{
		if (!PauseMenuWidget->IsInViewport())
		{
			PauseMenuWidget->AddToViewport();

			//UMG以外のインプットが反応しないようにする
			SetInputMode(FInputModeUIOnly().SetLockMouseToViewportBehavior(EMouseLockMode::LockOnCapture).SetWidgetToFocus(PauseMenuWidget->TakeWidget()));
			bShowMouseCursor = true;//マウスカーソルをON
		}
	}
}