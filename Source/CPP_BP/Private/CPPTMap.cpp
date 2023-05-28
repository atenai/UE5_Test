// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPTMap.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPTMap::ACPPTMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPTMap::BeginPlay()
{
	Super::BeginPlay();
	
	//foreachのinがElemにあたる、TPair<int, FString>は型でvarやintにあたる
	// TMapの中身を出力する
	for (TPair<int, FString> Elem : FruitMap)
	{
		UKismetSystemLibrary::PrintString(
			this
			, FString::Printf(TEXT("Key : %d Value : %s"), Elem.Key, *Elem.Value)
			, true
			, true
			, FColor::Cyan
			, 10.0f
			, TEXT("None"));
	}

	// 追加する
	FruitMap.Add(12, TEXT("Orange"));

	// 削除する
	FruitMap.Remove(3);

	// TMapの中身を出力する
	for (TPair<int, FString> Elem : FruitMap)
	{
		UKismetSystemLibrary::PrintString(
			this
			, FString::Printf(TEXT("Key : %d Value : %s"), Elem.Key, *Elem.Value)
			, true
			, true
			, FColor::Red
			, 10.0f
			, TEXT("None"));
	}
}

// Called every frame
void ACPPTMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

