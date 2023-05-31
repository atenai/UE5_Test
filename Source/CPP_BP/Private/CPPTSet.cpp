// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPTSet.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPTSet::ACPPTSet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPTSet::BeginPlay()
{
	Super::BeginPlay();
	
	// TSetの中身を出力する
	for (FString Elem : FruitSet)
	{
		UKismetSystemLibrary::PrintString(
			this
			, FString::Printf(TEXT("Value : %s"), *Elem)
			, true
			, true
			, FColor::Red
			, 10.0f
			, TEXT("None"));
	}

	// 追加する
	FruitSet.Add(TEXT("Orange"));

	// 削除する
	FruitSet.Remove(TEXT("Apple"));

	// TSetの中身を出力する
	for (FString Elem : FruitSet)
	{
		UKismetSystemLibrary::PrintString(
			this
			, FString::Printf(TEXT("Value : %s"), *Elem)
			, true
			, true
			, FColor::Orange
			, 10.0f
			, TEXT("None"));
	}
}

// Called every frame
void ACPPTSet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

