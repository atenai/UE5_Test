// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MyObject.h"

//C++のオーバーロードを使用した関数
int32 UCPP_MyObject::Add(int32 A, int32 B)
{
	return A + B;
}

//C++のオーバーロードを使用した関数
int32 UCPP_MyObject::Add(int32 A, int32 B, int32 C)
{
	return A + B + C;
}

//オーバーロードを使用する為のBlueprint用の関数
int32 UCPP_MyObject::BP_Add2(int32 A, int32 B)
{
	return UCPP_MyObject::Add(A, B);
}

//オーバーロードを使用する為のBlueprint用の関数
int32 UCPP_MyObject::BP_Add3(int32 A, int32 B, int32 C)
{
	return UCPP_MyObject::Add(A, B, C);
}

//テンプレート関数を使用する為のBlueprint用の関数
int32 UCPP_MyObject::BP_Add_Int(int32 A, int32 B)
{
	return UCPP_MyObject::Add<int32>(A, B);
}

//テンプレート関数を使用する為のBlueprint用の関数
double UCPP_MyObject::BP_Add_Double(double A, double B)
{
	return UCPP_MyObject::Add<double>(A, B);
}