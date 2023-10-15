// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPP_MyObject.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPP_MyObject : public UObject
{
	GENERATED_BODY()
	
	//C++のオーバーロードを使用した関数
	int32 Add(int32 A, int32 B);
	//C++のオーバーロードを使用した関数
	int32 Add(int32 A, int32 B, int32 C);

	//オーバーロードを使用する為のBlueprint用の関数
	UFUNCTION()
	int32 BP_Add2(int32 A, int32 B);
	//オーバーロードを使用する為のBlueprint用の関数
	UFUNCTION()
	int32 BP_Add3(int32 A, int32 B, int32 C);

	//C++のテンプレート関数
	template<class T> T Add(T A, T B)
	{
		return A + B;
	}

	//テンプレート関数を使用する為のBlueprint用の関数
	UFUNCTION()
	int32 BP_Add_Int(int32 A, int32 B);
	//テンプレート関数を使用する為のBlueprint用の関数
	UFUNCTION()
	double BP_Add_Double(double A, double B);
};
