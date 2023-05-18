// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPParentRedefinition.h"

ACPPParentRedefinition::ACPPParentRedefinition()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPParentRedefinition::BeginPlay()
{
	Super::BeginPlay();	
}

void ACPPParentRedefinition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPPParentRedefinition::SetPoint(int myPoint)
{
	point = myPoint;
}

int ACPPParentRedefinition::GetPoint()
{
	return point;
}