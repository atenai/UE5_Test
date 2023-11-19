// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_MainGameProjectile.h"
#include "CPP_EnemyProjectile.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API ACPP_EnemyProjectile : public ACPP_MainGameProjectile
{
	GENERATED_BODY()

public:
	ACPP_EnemyProjectile();

	virtual void Tick(float Deltatime);
};
