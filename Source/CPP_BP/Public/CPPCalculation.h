// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPCalculation.generated.h"

UCLASS()
class CPP_BP_API ACPPCalculation : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPCalculation();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	// PrintStringŠÖ”‚ÌDuration‚Éİ’è‚·‚é•Ï”
	const float Duration = 10.0f;

	// PrintStringŠÖ”‚ÌTextColor‚Éİ’è‚·‚é•Ï”
	const FLinearColor TextColor = FLinearColor(0.5, 0.66, 1.0);

	// ŒvZ—p‚Ì•Ï”
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

};
