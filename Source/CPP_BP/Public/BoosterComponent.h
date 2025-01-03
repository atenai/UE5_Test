// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BoosterComponent.generated.h"


UCLASS( ClassGroup=(Equipment), meta=(BlueprintSpawnableComponent) )
class CPP_BP_API UBoosterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBoosterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	double FuelMax = 60.0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	double FuelRest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnabled = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	double Power = 100.0;
		
	UFUNCTION(BlueprintPure)
	double GetVelocity() const;
};
