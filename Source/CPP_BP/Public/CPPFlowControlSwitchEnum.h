// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPCalcType.h" // �ǉ�
#include "GameFramework/Actor.h"
#include "CPPFlowControlSwitchEnum.generated.h"

UCLASS()
class CPP_BP_API ACPPFlowControlSwitchEnum : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPFlowControlSwitchEnum();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	// PrintString�֐���Duration�ɐݒ肷��ϐ�
	const float Duration = 30.0f;

	// PrintString�֐���TextColor�ɐݒ肷��ϐ�
	const FLinearColor TextColor = FColor(255, 255, 255);

	// �v�Z�p�̕ϐ�
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control�p�̕ϐ�
	bool IsPrintHello = false;
	//int32 CalcType = 1;
	ECPPCalcType CalcType = ECPPCalcType::Subtract;
};
