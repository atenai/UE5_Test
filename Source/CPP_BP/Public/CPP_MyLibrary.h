// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPP_MyLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPP_MyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static double Func(double In1, double In2);
};
