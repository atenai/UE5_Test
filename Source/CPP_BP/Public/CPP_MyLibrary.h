// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
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
};
