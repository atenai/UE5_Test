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

	//MouseY�����͂��ꂽ��o�C���h�����֐����ĂԂ悤�ɓo�^
	GetMutableDefault<UInputSettings>()->AddAxisMapping(FInputAxisKeyMapping("Player_MovePitch", EKeys::MouseY, 1.0f));//�����ŃA�����A���G���W���ɑ�����@��o�^
	InputComponent->BindAxis("Player_MovePitch", this, &ACPP_MainGamePlayerController::AddPitchInput);//�����œo�^����������@�Ɋ֐����o�C���h

	//���}�E�X�{�^���������ꂽ��o�C���h�����֐����ĂԂ悤�ɓo�^
	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Fire", EKeys::LeftMouseButton));//�����ŃA�����A���G���W���ɑ�����@��o�^
	InputComponent->BindAction("Player_Fire", IE_Pressed, this, &ACPP_MainGamePlayerController::Fire);//�����œo�^����������@�Ɋ֐����o�C���h
}

//"Player_MovePitch"���͂ɔ�������֐�
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

	//Super::BeginPlay�͍Ō�ɌĂ�ł����iBlueprint�̏�������ɍs����H���Q�Ɓj
	Super::BeginPlay();
}