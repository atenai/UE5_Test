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