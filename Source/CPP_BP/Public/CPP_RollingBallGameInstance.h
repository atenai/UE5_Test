// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CPP_RollingBallGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPP_RollingBallGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	//æ“¾‚µ‚½ƒRƒCƒ“‚Ì”
	int32 TotalCoints = 0;

	//Player‚ÌLife
	int32 TotalLifes = 3;

	//‰Šú‰»‚·‚é
	void Initialize();
};
