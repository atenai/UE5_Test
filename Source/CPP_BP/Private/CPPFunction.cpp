// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFunction.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

ACPPFunction::ACPPFunction()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPFunction::BeginPlay()
{
	Super::BeginPlay();
	
	// 変数を作成する
	FString Message = "C++ Hello World!";

	if (IsPrintHello)
	{
		// PrintStringノードと同じ処理
		// UKismetSystemLibraryクラスのPrintString関数を呼び出す
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	}
	else
	{
		// 計算結果を出力する処理
		PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);

		//switch (CalcType)
		//{
		//case ECPPCalcType::Add:
		//{
		//	// Add(足し算)の処理
		//	//int32 ResultAdd = CalcVarA + CalcVarB;

		//	// 値渡し
		//	int32 ResultAdd = Sum(CalcVarA, CalcVarB);
		//	FString StrResultAdd = FString::Printf(TEXT("Sum : %d + %d = %d"), CalcVarA, CalcVarB, ResultAdd);
		//	UKismetSystemLibrary::PrintString(
		//		this
		//		, StrResultAdd
		//		, true
		//		, true
		//		, FColor::Orange
		//		, Duration
		//		, TEXT("None"));

		//	// 参照渡し
		//	int32 ResultAddRef = SumRef(CalcVarA, CalcVarB);
		//	FString StrResultAddRef = FString::Printf(TEXT("SumRef : %d + %d = %d"), CalcVarA, CalcVarB, ResultAddRef);
		//	UKismetSystemLibrary::PrintString(
		//		this
		//		, StrResultAddRef
		//		, true
		//		, true
		//		, FColor::Yellow
		//		, Duration
		//		, TEXT("None"));
		//	break;
		//}
		//case ECPPCalcType::Subtract:
		//{
		//	// Subtract(引き算)の処理
		//	int32 ResultSubtract = CalcVarA - CalcVarB;
		//	FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
		//	UKismetSystemLibrary::PrintString(
		//		this
		//		, StrResultSubtract
		//		, true
		//		, true
		//		, FColor::Yellow
		//		, Duration
		//		, TEXT("None"));
		//	break;
		//}
		//case ECPPCalcType::Multiply:
		//{
		//	// Multiply(掛け算)の処理
		//	int32 ResultMultiply = CalcVarA * CalcVarB;
		//	FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
		//	UKismetSystemLibrary::PrintString(
		//		this
		//		, StrResultMultiply
		//		, true
		//		, true
		//		, FColor::Green
		//		, Duration
		//		, TEXT("None"));
		//	break;
		//}
		//case ECPPCalcType::Divide:
		//{
		//	// Divide(割り算)の処理
		//	float ResultDivide = (float)CalcVarA / (float)CalcVarB;
		//	FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
		//	UKismetSystemLibrary::PrintString(
		//		this
		//		, StrResultDivide
		//		, true
		//		, true
		//		, FColor::Blue
		//		, Duration
		//		, TEXT("None"));
		//	break;
		//}
		//}
	}
}

void ACPPFunction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 ACPPFunction::Sum(int32 A, int32 B)
{
	//return A + B;
	/*int32 LocalResult = A + B;
	return LocalResult;*/

	//A = 9;
	//B = 7;
	return A + B;
}

int32 ACPPFunction::SumRef(const int32& A, const int32& B)
{
	//return A + B;

	//A = 9;
	//B = 7;
	return A + B;
}

void ACPPFunction::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
	case ECPPCalcType::Add:
	{
		// Add(足し算)の処理
		int32 ResultAdd = Sum(CalcVarA, CalcVarB);
		FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultAdd
			, true
			, true
			, FColor::Red
			, Duration
			, TEXT("None"));
		break;
	}
	case ECPPCalcType::Subtract:
	{
		// Subtract(引き算)の処理
		int32 ResultSubtract = CalcVarA - CalcVarB;
		FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultSubtract
			, true
			, true
			, FColor::Yellow
			, Duration
			, TEXT("None"));
		break;
	}
	case ECPPCalcType::Multiply:
	{
		// Multiply(掛け算)の処理
		int32 ResultMultiply = CalcVarA * CalcVarB;
		FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultMultiply
			, true
			, true
			, FColor::Green
			, Duration
			, TEXT("None"));
		break;
	}
	case ECPPCalcType::Divide:
	{
		// Divide(割り算)の処理
		float ResultDivide = (float)CalcVarA / (float)CalcVarB;
		FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultDivide
			, true
			, true
			, FColor::Blue
			, Duration
			, TEXT("None"));
		break;
	}
	}
}

