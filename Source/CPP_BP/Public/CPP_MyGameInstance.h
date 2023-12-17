// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPP_MyGameTypes.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CPP_MyGameInstance.generated.h"


UCLASS()
class CPP_BP_API UCPP_MyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UCPP_MyGameInstance();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MainGameConfig")
	EMyGameDifficultType DifficultType;
};
