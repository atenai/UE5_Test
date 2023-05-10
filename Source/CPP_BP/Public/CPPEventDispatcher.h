// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPCalcType.h"
#include "CPPEventDispatcher.generated.h"

// 1. delegate�̐錾��ǉ�����ꍇ�ɂ�Global�X�R�[�v�ɒǉ����邱�Ƃ������ł��B
// �����ɒǉ�


UCLASS()
class CPP_BP_API ACPPEventDispatcher : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPEventDispatcher();

	// Custom Event[PrintHello] 
	UFUNCTION()
		void PrintHello();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	int32 Sum(int32 A, int32 B);

	// Action Mappings�ɐݒ肵��Action����������֐�
	void PressedActionPrintCalcResult();

private:
	FString Message = "C++ Hello World!";

	// �v�Z���ʂ��o�͂���֐�
	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

	// PrintString�֐���Duration�ɐݒ肷��ϐ�
	const float Duration = 10.0f;

	// PrintString�֐���TextColor�ɐݒ肷��ϐ�
	const FLinearColor TextColor = FColor(255, 255, 255);

	// �v�Z�p�̕ϐ�
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control�p�̕ϐ�
	bool IsPrintHello = false;
	ECPPCalcType CalcType = ECPPCalcType::Add;

	// Input�ݒ�
	void SetupInput();

	// Input Event����������֐�
	void PressedH();

public:
	// 2. class����delegate�̐錾���������Ƃ��\��
	// Blueprint�A�g����ꍇ�ɂ͂�����ɏ������Ƃ������ł�
	// �����ɒǉ�

	// Event Dispatcher[OnPrintHello]
	// DECLARE_DYNAMIC_MULTICAST_DELEGATE�Ɋւ��Ă�Blueprint�ƘA�g�\
	//DECLARE_DYNAMIC_MULTICAST_DELEGATE(�f���Q�[�g�̌^��);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrintHelloDelegate);

	// Blueprint����A�T�C���\�ɂ��邽�߂�BlueprintAssignable��t�^����
	UPROPERTY(BlueprintAssignable, Category = "CPP_BP")
		FPrintHelloDelegate OnPrintHello;//��ō쐬����FPrintHelloDelegate�̃f���Q�[�g�^��OnPrintHello�f���Q�[�g���쐬����

};
