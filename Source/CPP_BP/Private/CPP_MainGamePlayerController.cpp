// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainGamePlayerController.h"
#include "GameFramework/InputSettings.h"
#include "CPP_PlayerPawn.h"

void ACPP_MainGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	//MouseY�����͂��ꂽ��ACPPMainGamePlayerController::AddPitchInput�֐����ĂԂ悤�ɓo�^
	GetMutableDefault<UInputSettings>()->AddAxisMapping(FInputAxisKeyMapping("Player_MovePitch", EKeys::MouseY, 1.0f));
	InputComponent->BindAxis("Player_MovePitch", this, &ACPP_MainGamePlayerController::AddPitchInput);
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