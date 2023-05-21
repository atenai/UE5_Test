// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAbstractParent.generated.h"

UCLASS(Abstract)//抽象クラスの場合は引数にAbstractを入れる
class CPP_BP_API ACPPAbstractParent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPAbstractParent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

		// 派生クラスで値を設定する
	UPROPERTY(EditAnywhere, Category = Default)
	FString GreetingMessage;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 挨拶する
	virtual void Greeting(FString message) PURE_VIRTUAL(ACPPAbstractParent::Greeting, );//純粋仮想関数には、PURE_VIRTUALを指定します。
	// 戻り値がある場合
	//virtual int sum(int A, intB) PURE_VIRTUAL(ACPPAbstractParent::sum, return 0;);
};
