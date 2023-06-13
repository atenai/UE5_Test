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