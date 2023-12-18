// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_MySmallStruct.generated.h"

USTRUCT(BlueprintType)
struct CPP_BP_API FCPP_MySmallStruct
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName EnemyName;

	FCPP_MySmallStruct() : EnemyName(TEXT("Enemy"))
	{

	}
};
