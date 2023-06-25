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

void UMathLibrary::AddRef(UPARAM(ref) double& A, double B)
{
	A = A + B;//A + B �̌��ʂ�A�i�Q�Ɠn���j�ɑ��
}

double UMathLibrary::AddCompact(double A, double B)
{
	double C;

	C = A + B;
	return C;
}

double UMathLibrary::Clamp(double Value, double Min, double Max)
{
	if (Value < Min)
	{
		return Min;
	}
	else if (Max < Value)
	{
		return Max;
	}
	else 
	{
		return Value;
	}
}

int32 UMathLibrary::Accumulate(int32 N)
{
	int32 Out = 0;

	for(int32 i = 1; i <= N; i++)
	{
		Out = Out + i;
	}

	return Out;
}

void UMathLibrary::MinMax(double A, double B, double C, double& Min, double& Max)
{
	Min = UKismetMathLibrary::FMin(UKismetMathLibrary::FMin(A, B), C);
	Max = UKismetMathLibrary::FMax(UKismetMathLibrary::FMax(A, B), C);
}