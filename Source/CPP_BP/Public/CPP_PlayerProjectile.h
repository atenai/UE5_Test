// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_MainGameProjectile.h"
#include "CPP_PlayerProjectile.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API ACPP_PlayerProjectile : public ACPP_MainGameProjectile
{
	GENERATED_BODY()
	
public:
	ACPP_PlayerProjectile();

	virtual void Tick(float DeltaTime) override;
};
