// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_TitleMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API ACPP_TitleMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACPP_TitleMenuPlayerController();
	
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnPushedEasyButton();

	UFUNCTION()
	void OnPushedHardButton();

private:
	TSubclassOf<class UUserWidget> TitleMenuWidgetClass;

	UPROPERTY()
	class UCPP_TitleMenuWidget* TitleMenuWidget;
};
