// Fill out your copyright notice in the Description page of Project Settings.


#include "MathLibrary.h"

double UMathLibrary::Add(double A, double B)
{
	double C;//���[�J���֐�C�̒�`

	C = A + B;//A + B �̌��ʂ�C�ɑ��
	return C;//C�̒l���o��
}

void UMathLibrary::Divide(int32 A, int32 B, int32& Quotient, int32& Remainder)
{
	Quotient = A / B;//A �� B �̏���Quotient�ɑ���i�o�́j
	Remainder = A % B;//A �� B �̗]���Remainder�ɑ���i�o�́j
}