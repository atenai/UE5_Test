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

	// �h���N���X�Œl��ݒ肷��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FString GreetingMessage;

public:	
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION��BlueprintNativeEvent���`���邱�ƂŁABlueprint��C++�̗�����Override�ł��܂��B
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Greeting();
};
