// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MyObject.h"

//C++�̃I�[�o�[���[�h���g�p�����֐�
int32 UCPP_MyObject::Add(int32 A, int32 B)
{
	return A + B;
}

//C++�̃I�[�o�[���[�h���g�p�����֐�
int32 UCPP_MyObject::Add(int32 A, int32 B, int32 C)
{
	return A + B + C;
}

//�I�[�o�[���[�h���g�p����ׂ�Blueprint�p�̊֐�
int32 UCPP_MyObject::BP_Add2(int32 A, int32 B)
{
	return UCPP_MyObject::Add(A, B);
}

//�I�[�o�[���[�h���g�p����ׂ�Blueprint�p�̊֐�
int32 UCPP_MyObject::BP_Add3(int32 A, int32 B, int32 C)
{
	return UCPP_MyObject::Add(A, B, C);
}

//�e���v���[�g�֐����g�p����ׂ�Blueprint�p�̊֐�
int32 UCPP_MyObject::BP_Add_Int(int32 A, int32 B)
{
	return UCPP_MyObject::Add<int32>(A, B);
}

//�e���v���[�g�֐����g�p����ׂ�Blueprint�p�̊֐�
double UCPP_MyObject::BP_Add_Double(double A, double B)
{
	return UCPP_MyObject::Add<double>(A, B);
}