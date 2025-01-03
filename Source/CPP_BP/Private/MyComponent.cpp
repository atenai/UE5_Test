// Fill out your copyright notice in the Description page of Project Settings.


#include "MyComponent.h"

// Sets default values for this component's properties
UMyComponent::UMyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyComponent::BeginPlay()
{
	Super::BeginPlay();

	MemberVar = 1.0;
}


// Called every frame
void UMyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyComponent::Func(double In1, double In2, double& Out1, double& Out2)
{
	double LocalVar;

	LocalVar = In1 + In2;
	Out1 = LocalVar / 2.0;
	Out2 = LocalVar * 2.0;
}
