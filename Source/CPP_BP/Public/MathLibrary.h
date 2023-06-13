// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

	UFUNCTION(BlueprintCallable)
	static double Add(double A, double B);

	UFUNCTION(BlueprintCallable)
	static void Divide(int32 A, int32 B, int32& Quotient, int32& Remainder);
};
