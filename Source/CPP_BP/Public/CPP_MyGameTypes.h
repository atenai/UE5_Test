// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_MyGameTypes.generated.h"

UENUM(BlueprintType)
enum class EMyGameDifficultType : uint8
{
	NONE,
	EASY,
	HARD,
};
