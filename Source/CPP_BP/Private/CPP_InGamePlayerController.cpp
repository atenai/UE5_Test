// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGamePlayerController.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "CPP_InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"

ACPP_InGamePlayerController::ACPP_InGamePlayerController()
{
	//InputAction「IA_Pause」を読み込む
	PauseAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Pause"));
}

void ACPP_InGamePlayerController::BeginPlay()
{
	//入力をGameのみにする
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(this, false);

	//マウスを非表示にする
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
	//inputのValueはboolに変換する
	if (const bool V = Value.Get<bool>())
	{
		if (ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(GetHUD()))
		{
			//Pauseメニューの表示/非表示を実行する
			HUD->DispPause(!UGameplayStatics::IsGamePaused(GetWorld()));
		}
	}
}