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
	//取得したコインの数
	int32 TotalCoints = 0;

	//PlayerのLife
	int32 TotalLifes = 3;

	//初期化する
	void Initialize();
};
