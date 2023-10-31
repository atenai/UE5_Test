// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGamePlayerController.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "CPP_InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"

ACPP_InGamePlayerController::ACPP_InGamePlayerController()
{
	//InputAction�uIA_Pause�v��ǂݍ���
	PauseAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Pause"));
}

void ACPP_InGamePlayerController::BeginPlay()
{
	//���͂�Game�݂̂ɂ���
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(this, false);

	//�}�E�X���\���ɂ���
	SetShowMouseCursor(false);
}

void ACPP_InGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//SetUpActionBindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Triggered, this, &ACPP_InGamePlayerController::DispPause);
	}
}

void ACPP_InGamePlayerController::DispPause(const FInputActionValue& Value)
{
	//input��Value��bool�ɕϊ�����
	if (const bool V = Value.Get<bool>())
	{
		if (ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(GetHUD()))
		{
			//Pause���j���[�̕\��/��\�������s����
			HUD->DispPause(!UGameplayStatics::IsGamePaused(GetWorld()));
		}
	}
}