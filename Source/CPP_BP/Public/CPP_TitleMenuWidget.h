// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_TitleMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPP_TitleMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//イニシャライズを作成
	virtual bool Initialize() override;

	UPROPERTY()
	class UButton* SelectEasyButton;

	UPROPERTY()
	class UButton* SelectHardButton;
};
