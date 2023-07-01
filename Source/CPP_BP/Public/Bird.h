// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bird.generated.h"

UCLASS()
class CPP_BP_API ABird : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABird();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	double Weight = 10.0;

	UPROPERTY(EditDefaultsOnly)
	bool bFlyable = true; 

	UPROPERTY(EditInstanceOnly)
	int32 VitalityMax = 100;

	UPROPERTY()
	int32 Vitality = 100;

	UPROPERTY(VisibleAnywhere)
	bool bPoisoned = false;

	UPROPERTY(VisibleDefaultsOnly)
	int32 BirdID = -1;

	UPROPERTY(VisibleInstanceOnly)
	int32 InstanceID = -1;
};
