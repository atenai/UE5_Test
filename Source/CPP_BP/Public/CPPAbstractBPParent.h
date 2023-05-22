// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAbstractBPParent.generated.h"

UCLASS(BlueprintType, Blueprintable, Abstract)
class CPP_BP_API ACPPAbstractBPParent : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPAbstractBPParent();

protected:
	virtual void BeginPlay() override;

	// 派生クラスで値を設定する
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FString GreetingMessage;

public:	
	virtual void Tick(float DeltaTime) override;

	//UFUNCTIONにBlueprintNativeEventを定義することで、BlueprintとC++の両方でOverrideできます。
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Greeting();
};
