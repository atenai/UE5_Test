// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
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
};
