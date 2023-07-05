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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter", meta = (ClampMin = 0.0f, ClampMax = 1000.0f))
	double Weight = 10.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Parameter")
	bool bFlyable = true; 

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Parameter", meta = (ClampMin = 1.0f, ClampMax = 5000.0f))
	int32 VitalityMax = 100;

	UPROPERTY()
	int32 Vitality = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Status")
	bool bPoisoned = false;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Internal")
	int32 BirdID = -1;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Internal")
	int32 InstanceID = -1;

	UFUNCTION(BlueprintCallable)
	void Damage(int32 Amount);

	UFUNCTION(BlueprintCallable)
	void Cure(int32 Amount);

	UFUNCTION(BlueprintPure)
	int32 GetVitality();
};
