// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAbstractBPParent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPAbstractBPParent::ACPPAbstractBPParent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPAbstractBPParent::BeginPlay()
{
	Super::BeginPlay();
	
	// ���A����
	Greeting();
}

// Called every frame
void ACPPAbstractBPParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPAbstractBPParent::Greeting_Implementation()
{
}