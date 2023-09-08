// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_MyEnum.generated.h"

UENUM(BlueprintType) 
enum class ECPP_MyEnum : uint8 
{
	E_Test = 0 UMETA(DisplayName = "Test"),
};
