// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPVariable.generated.h"

UCLASS()
class CPP_BP_API ACPPVariable : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPVariable();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	// PrintString関数のDurationに設定する変数
	const float Duration = 10.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FLinearColor(1.0, 0.0, 1.0);
};
