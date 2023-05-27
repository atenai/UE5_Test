// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPRotatingComponent.h"

// Sets default values for this component's properties
UCPPRotatingComponent::UCPPRotatingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPPRotatingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// OwnerのRotationを取得する
	OwnerRotation = GetOwner()->GetRootComponent()->GetComponentRotation();

	// Timerをセットする
	FTimerHandle handle;
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(handle, this, &UCPPRotatingComponent::RotateLoop, Interval, true);
}


// Called every frame
void UCPPRotatingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCPPRotatingComponent::RotateLoop()
{
	// OwnerのRotationを更新する
	OwnerRotation = FRotator(OwnerRotation.Pitch + RotY, OwnerRotation.Yaw + RotZ, OwnerRotation.Roll + RotX);
	GetOwner()->GetRootComponent()->SetWorldRotation(OwnerRotation);
}