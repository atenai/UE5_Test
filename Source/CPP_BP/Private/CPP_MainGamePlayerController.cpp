// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainGamePlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "CPP_PlayerPawn.h"
#include "Engine.h"

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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fire1"));
	ACPP_PlayerPawn* PossessedPawn = Cast<ACPP_PlayerPawn>(GetPawn());
	if (PossessedPawn != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fire2"));
		PossessedPawn->Fire();
	}
}