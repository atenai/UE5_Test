// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPCalcType.h"
#include "CPPFunction.generated.h"

UCLASS()
class CPP_BP_API ACPPFunction : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPFunction();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	int32 Sum(int32 A, int32 B);

	int32 SumRef(const int32& A, const int32& B);

	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

private:
	// PrintStringŠÖ”‚ÌDuration‚Éİ’è‚·‚é•Ï”
	const float Duration = 10.0f;

	// PrintStringŠÖ”‚ÌTextColor‚Éİ’è‚·‚é•Ï”
	const FLinearColor TextColor = FColor(255, 255, 255);

	// ŒvZ—p‚Ì•Ï”
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control—p‚Ì•Ï”
	bool IsPrintHello = false;
	ECPPCalcType CalcType = ECPPCalcType::Add;
};
