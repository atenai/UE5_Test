// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAccessParent.generated.h"

UCLASS()
class CPP_BP_API ACPPAccessParent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPAccessParent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 親クラスのメンバ関数(Public)
	UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint)
	void CallPublicFunc();

	// 親クラスのデータメンバ(Public)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	int VarPublicNum = 10;

protected:

	// 親クラスのメンバ関数(Protected)
	UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint)
	void CallProtectedFunc();

	// 親クラスのデータメンバ(Protected)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	int VarProtectedNum = 20;

private:

	// 親クラスのメンバ関数(Private)
	//UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint)
	void CallPrivateFunc();

	// 親クラスのデータメンバ(Private)
	//UPROPERTY(EditAnywhere, Category = Default)
	int VarPrivateNum = 30;
};
