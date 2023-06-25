// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"//’Ç‰Á
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

	UFUNCTION(BlueprintCallable)
	static void AddRef(UPARAM(ref) double& A, double B);

	UFUNCTION(BlueprintPure, Category = "Math", meta = (CompactNodeTitle = "+"))
	static double AddCompact(double A , double B);

	UFUNCTION(BlueprintCallable, Category = "Math")
	static double Clamp(double Value, double Min, double Max);

	UFUNCTION(BlueprintCallable, Category = "Math")
	static int32 Accumulate(int32 N);

	//UFUNCTION(BlueprintCallable, Category = "Math", meta = (CompactNodeTitle = "MinMax"))
	UFUNCTION(BlueprintCallable, Category = "Math")
	static void MinMax(double A, double B, double C, double& Min, double& Max);
};
