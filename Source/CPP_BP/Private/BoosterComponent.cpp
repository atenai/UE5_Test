// Fill out your copyright notice in the Description page of Project Settings.


#include "BoosterComponent.h"

// Sets default values for this component's properties
UBoosterComponent::UBoosterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBoosterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBoosterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

double UBoosterComponent::GetVelocity() const
{
	if (bEnabled == true && 0.0 < FuelRest)
	{
		return Power;
	}

	return 0.0;
}