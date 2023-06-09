// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPFlowControlSwitch.generated.h"

UCLASS()
class CPP_BP_API ACPPFlowControlSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPFlowControlSwitch();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	// PrintString関数のDurationに設定する変数
	const float Duration = 30.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FColor(0, 0, 0);

	// 計算用の変数
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control用の変数
	bool IsPrintHello = false;
	int32 CalcType = 2;
};
