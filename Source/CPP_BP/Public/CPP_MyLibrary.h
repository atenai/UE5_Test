// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"//�ǉ�
#include "CPP_MyLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPP_MyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static double Func(double In1, double In2);

	//�����̌^�ɑ΂���&������Əo�͂ɂȂ�
	//�iC++����return�ŏo�͒l��������ݒ�ł��Ȃ����A�����A���G���W���͕����̏o�͒l���m�[�h�ŏo�����Ƃ��ł����̍ۂɂ���&�����ĕ����̏o�͒l�����j
	//�܂�return���Ƃ����ŏ������I��邪�����return���g��Ȃ��̂ŏ���������
	UFUNCTION(BlueprintCallable)
	static void Func2(double In1, double In2, double& Out1, double& Out2);

	//�Q�Ɠn���̋L�q���@�́A�����̌^�̑O�ɑ΂���UPARAM(ref)�����āA�����̌^�̌���&���L�q���A�����̖��O�ɓ��͖��i�Q�Ɠn���j���L�q����K�v������
	UFUNCTION(BlueprintCallable)
	static void Func3(double In, UPARAM(ref) double& InRef);

	//�Q�Ɠn���ł̕����̏o�͒l
	UFUNCTION(BlueprintCallable)
	static void Func4(double In, UPARAM(ref) double& InRef, double& Out);

	//const�Q�Ɠn���͈����̌^�̑O��const�����āA�����̌^�̌���&���L�q���A�����̖��O�ɓ��͖��i�Q�Ɠn���j���L�q����K�v������
	//UPARAM(ref)�̋L�q�͕s�v
	UFUNCTION(BlueprintCallable)
	static double Func5(double In, const double& InRef);

	//�����̉��Z�q
	UFUNCTION(BlueprintCallable)
	static void Func6(double In1, double In2, double In3, double& Out);

	//��������
	UFUNCTION(BlueprintCallable)
	static double Func7(bool bCondA, bool bCondB, double Val1, double Val2);

	//���[�v
	UFUNCTION(BlueprintCallable)
	static int32 Func8(int32 In1, int32 In2);

	//�A�����A���G���W���̃��C�u�����֐��̌Ăяo��
	UFUNCTION(BlueprintCallable)
	static void Func9();
};
