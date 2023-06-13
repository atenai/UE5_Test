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
};