// Fill out your copyright notice in the Description page of Project Settings.


#include "TestKashiwabara.h"
#include "Kismet/KismetSystemLibrary.h"

ATestKashiwabara::ATestKashiwabara()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATestKashiwabara::BeginPlay()
{
	Super::BeginPlay();


	UKismetSystemLibrary::PrintString(this, test, true, true, TextColor, 100);	
}

void ATestKashiwabara::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

