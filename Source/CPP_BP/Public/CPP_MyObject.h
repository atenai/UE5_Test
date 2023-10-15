// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPP_MyObject.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPP_MyObject : public UObject
{
	GENERATED_BODY()
	
	//C++�̃I�[�o�[���[�h���g�p�����֐�
	int32 Add(int32 A, int32 B);
	//C++�̃I�[�o�[���[�h���g�p�����֐�
	int32 Add(int32 A, int32 B, int32 C);

	//�I�[�o�[���[�h���g�p����ׂ�Blueprint�p�̊֐�
	UFUNCTION()
	int32 BP_Add2(int32 A, int32 B);
	//�I�[�o�[���[�h���g�p����ׂ�Blueprint�p�̊֐�
	UFUNCTION()
	int32 BP_Add3(int32 A, int32 B, int32 C);

	//C++�̃e���v���[�g�֐�
	template<class T> T Add(T A, T B)
	{
		return A + B;
	}

	//�e���v���[�g�֐����g�p����ׂ�Blueprint�p�̊֐�
	UFUNCTION()
	int32 BP_Add_Int(int32 A, int32 B);
	//�e���v���[�g�֐����g�p����ׂ�Blueprint�p�̊֐�
	UFUNCTION()
	double BP_Add_Double(double A, double B);
};
