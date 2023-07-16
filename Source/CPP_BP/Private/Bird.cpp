// Fill out your copyright notice in the Description page of Project Settings.


#include "Bird.h"

// Sets default values
ABird::ABird()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Weight = 50.0; 
	bFlyable = false;
}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	
	Vitality = VitalityMax;
	InstanceID = UKismetMathLibrary::RandomInteger(100000);
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bPoisoned == true)
	{
		Damage(1);
	}
	else
	{
		Cure(1);
	}
}

void ABird::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	if (bFlyable)
	{
		BirdID = 0;
	}
	else 
	{
		BirdID = 1;
	}
}

void ABird::FuncTest()
{

}

void ABird::Damage(int32 Amount)
{
	Vitality = Vitality - Amount;

	if (Vitality < 0)
	{
		Vitality = 0;
	}
}

void ABird::Cure(int32 Amount)
{
	Vitality = Vitality + Amount;

	if (VitalityMax < Vitality)
	{
		Vitality = VitalityMax;
	}
}

int32 ABird::GetVitality() const
{
	return Vitality;
}

double ABird::GetWalkingSpeed() const
{
	return UKismetMathLibrary::FMin(10.0 - 0.01 * Weight, 5.0);
}

double ABird::GetFlightSpeed() const
{
	if (!bFlyable)
	{
		return 0.0;
	}

	return UKismetMathLibrary::FMin(50.0 - 0.05 * Weight, 25.0);
}