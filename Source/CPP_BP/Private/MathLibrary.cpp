// Fill out your copyright notice in the Description page of Project Settings.


#include "MathLibrary.h"

double UMathLibrary::Add(double A, double B)
{
	double C;//ローカル関数Cの定義

	C = A + B;//A + B の結果をCに代入
	return C;//Cの値を出力
}

void UMathLibrary::Divide(int32 A, int32 B, int32& Quotient, int32& Remainder)
{
	Quotient = A / B;//A ÷ B の商をQuotientに代入（出力）
	Remainder = A % B;//A ÷ B の余りをRemainderに代入（出力）
}

void UMathLibrary::AddRef(UPARAM(ref) double& A, double B)
{
	A = A + B;//A + B の結果をA（参照渡し）に代入
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