// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_MyStruct.generated.h"

USTRUCT(BlueprintType)
struct FCPP_MyStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0, ClampMax = 10)) 
	int Var1 = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	bool Var2 = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0.0f, ClampMax = 10.0f)) 
	double Var3 = 1.0f;
};