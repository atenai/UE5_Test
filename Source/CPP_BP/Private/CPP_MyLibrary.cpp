// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MyLibrary.h"

double UCPP_MyLibrary::Func(double In1, double In2) 
{
	double LocalVar;

	LocalVar = In1 + In2;
	return LocalVar;//出力値
}


//引数の型に対して&をつけると出力になる
//（C++だとreturnで出力値が一つしか設定できないがアンリアルエンジンは複数の出力値をノードで出すことができその際にこの&をつけて複数の出力値を作る）
//またreturnだとそこで処理が終わるがこれはreturnを使わないので処理が続く
void UCPP_MyLibrary::Func2(double In1, double In2, double& Out1, double& Out2)
{
	Out1 = In1 + In2;//Out1の出力値
	Out2 = In1 - In2;//Out2の出力値
}

//参照渡しの記述方法は、引数の型の前に対してUPARAM(ref)をつけて、引数の型の後ろに&を記述し、引数の名前に入力名（参照渡し）を記述する必要がある
void UCPP_MyLibrary::Func3(double In, UPARAM(ref) double& InRef)
{
	InRef = InRef + In;
}

//参照渡しでの複数の出力値
void UCPP_MyLibrary::Func4(double In, UPARAM(ref) double& InRef, double& Out)
{

}

//const参照渡しは引数の型の前にconstをつけて、引数の型の後ろに&を記述し、引数の名前に入力名（参照渡し）を記述する必要がある
//UPARAM(ref)の記述は不要
double UCPP_MyLibrary::Func5(double In, const double& InRef)
{
	return In + InRef;
}

//複数の演算子
void UCPP_MyLibrary::Func6(double In1, double In2, double In3, double& Out)
{
	Out = (In1 + In2) * 2.0 - In3;

	//たとえば、In1 = 5.0, In2 = 3.0, In3 = 10.0 のとき
	//Out = (5.0 + 3.0) * 2.0 - 10.0 = 6.0 になる
}

//条件分岐
double UCPP_MyLibrary::Func7(bool bCondA, bool bCondB, double Val1, double Val2)
{
	double LocalVar;

	if (bCondA && bCondB)//bCondAが真かつbCondBが真の場合、中身が実行される
	{
		LocalVar = Val1 + Val2;
	}
	else if (0.0 < Val2)//上の条件が偽であり、なおかつVal2が0.0より大きい場合、中身が実行される
	{
		LocalVar = Val2;
	}
	else//上の条件がいずれも偽である場合に中身が実行される
	{
		LocalVar = 0.0;
	}

	return LocalVar;//if～elseの後の処理は共通で行われる
}

//ループ
int32 UCPP_MyLibrary::Func8(int32 In1, int32 In2)
{
	for (int32 Index = 0; Index < In1; Index++)
	{
		//Indexの初期値を0とし、Index < In1が真である限りループする。
		//ループ毎に、Indexを1ずつ加算する。
		In2 += Index;//ループ毎に、この処理が行われる。
	}
	return In2;
}

//アンリアルエンジンのライブラリ関数の呼び出し
void UCPP_MyLibrary::Func9()
{
	UKismetMathLibrary::FMin(10.0, 5.0);
}

void UCPP_MyLibrary::Func10()
{

}