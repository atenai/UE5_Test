// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "CPP_InGamePlayerController.generated.h"

class UInputAction;

UCLASS()
class CPP_BP_API ACPP_InGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//コンストラクタ
	ACPP_InGamePlayerController();

	//ACPP_InGamePlayerControllerからOverrideする
	virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;

	//Pauseメニューを表示する
	void DispPause(const FInputActionValue& Value);

private:
	//Pause Input Action
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> PauseAction;
};
