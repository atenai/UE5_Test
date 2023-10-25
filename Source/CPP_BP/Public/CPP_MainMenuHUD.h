// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CPP_MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API ACPP_MainMenuHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
