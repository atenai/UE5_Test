// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_PauseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPP_PauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* GoToTitleButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CloseMenuButton;

	UFUNCTION()
	void OnClickedGoToTitle();

	UFUNCTION()
	void OnClickedClose();
};
