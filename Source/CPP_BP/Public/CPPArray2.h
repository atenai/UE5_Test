// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPArray2.generated.h"

UCLASS()
class CPP_BP_API ACPPArray2 : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPArray2();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	//配列を定義する。
	TArray<FString> Fruits;

	//Default Valueを設定します。
	TArray<FString> Fruits2 = 
	{
		TEXT("Apple"),//0
		TEXT("Lemon"),//1
		TEXT("Banana")//2
	};

	TArray<FString> FruitsLocal;

	TArray<FString> Fruits3 = 
	{
		TEXT("Apple"),
		TEXT("Lemon"),
		TEXT("Banana"),
	};

	TArray<FString> Vegetables = 
	{
		TEXT("Carrot"),
		TEXT("Tomato"),
		TEXT("Onion"),
	};

	TArray<FString> Fruits4 =
	{
		TEXT("Apple"),
		TEXT("Lemon"),
		TEXT("Banana"),
		TEXT("Apple"),
	};

	TArray<FString> Fruits5 =
	{
		TEXT("Apple"),
		TEXT("Lemon"),
		TEXT("Banana"),
		TEXT("Apple"),
	};

	//ソート用の配列を用意します。
	TArray<FString> SortArray =
	{
		TEXT("Apple"),
		TEXT("Lemon"),
		TEXT("Banana"),
		TEXT("Carrot"),
		TEXT("Tomato"),
		TEXT("Onion"),
	};
};
