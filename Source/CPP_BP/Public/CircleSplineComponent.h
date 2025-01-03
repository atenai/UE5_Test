// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "CircleSplineComponent.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCircleSplineComponent : public USplineComponent
{
	GENERATED_BODY()
	
public:
	
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	UPROPERTY(EditAnywhere)
	double Radius = 300.0f;

	UPROPERTY(EditAnywhere)
	int32 PointNum = 30;
};
