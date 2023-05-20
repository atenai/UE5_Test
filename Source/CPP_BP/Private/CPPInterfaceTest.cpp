// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPInterfaceTest.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPInterfaceTest::ACPPInterfaceTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPInterfaceTest::BeginPlay()
{
	Super::BeginPlay();
	
	PrintHello();

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Add(1+2)= %d"), Add(1, 2)), true, true, FColor::Cyan, 10.f, TEXT("None"));
}

// Called every frame
void ACPPInterfaceTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPInterfaceTest::PrintHello()
{
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Override Hello!")), true, true, FColor::Red, 10.f, TEXT("None"));
}

int ACPPInterfaceTest::Add(int A, int B)
{
	return A + B + A + B;
}