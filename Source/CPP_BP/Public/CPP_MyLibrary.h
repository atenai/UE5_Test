// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"//追加
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

	//引数の型に対して&をつけると出力になる
	//（C++だとreturnで出力値が一つしか設定できないがアンリアルエンジンは複数の出力値をノードで出すことができその際にこの&をつけて複数の出力値を作る）
	//またreturnだとそこで処理が終わるがこれはreturnを使わないので処理が続く
	UFUNCTION(BlueprintCallable)
	static void Func2(double In1, double In2, double& Out1, double& Out2);

	//参照渡しの記述方法は、引数の型の前に対してUPARAM(ref)をつけて、引数の型の後ろに&を記述し、引数の名前に入力名（参照渡し）を記述する必要がある
	UFUNCTION(BlueprintCallable)
	static void Func3(double In, UPARAM(ref) double& InRef);

	//参照渡しでの複数の出力値
	UFUNCTION(BlueprintCallable)
	static void Func4(double In, UPARAM(ref) double& InRef, double& Out);

	//const参照渡しは引数の型の前にconstをつけて、引数の型の後ろに&を記述し、引数の名前に入力名（参照渡し）を記述する必要がある
	//UPARAM(ref)の記述は不要
	UFUNCTION(BlueprintCallable)
	static double Func5(double In, const double& InRef);

	//複数の演算子
	UFUNCTION(BlueprintCallable)
	static void Func6(double In1, double In2, double In3, double& Out);

	//条件分岐
	UFUNCTION(BlueprintCallable)
	static double Func7(bool bCondA, bool bCondB, double Val1, double Val2);

	//ループ
	UFUNCTION(BlueprintCallable)
	static int32 Func8(int32 In1, int32 In2);

	//アンリアルエンジンのライブラリ関数の呼び出し
	UFUNCTION(BlueprintCallable)
	static void Func9();

public://他のソースコードから呼び出す場合は必ずpublic:の下に書く必要がある

	UFUNCTION(BlueprintCallable)
	static void Func10();
};
