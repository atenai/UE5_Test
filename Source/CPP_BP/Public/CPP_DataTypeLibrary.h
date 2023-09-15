// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPP_DataTypeLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPP_DataTypeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static void ComponentWiseSquared(FVector In, FVector& Out);

	UFUNCTION(BlueprintCallable)
	static void AddRotationAngle(FRotator In, double X, double Y, double Z, FRotator& Out);
};
