// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // 追加
#include "Kismet/KismetMathLibrary.h" // 追加

ACPPCalculation::ACPPCalculation()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPCalculation::BeginPlay()
{
	Super::BeginPlay();
	
	// 変数を作成する
	FString Message = "C++ Hello World!";

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(
		this
		, Message
		, true
		, true
		, TextColor// Textのカラー情報に変数TextColorを設定
		, Duration
		, TEXT("None"));

	// Add(足し算)の処理
	//A + Bの計算
	int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
	//上で計算した数値をint型からstring型に変更
	FString StrResultAdd = UKismetStringLibrary::Conv_IntToString(ResultAdd);
	//string型に変更した文字列を描画
	UKismetSystemLibrary::PrintString(
		this
		, StrResultAdd
		, true
		, true
		, FColor::Red
		, Duration
		, TEXT("None"));

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

	// Divide(割り算)の処理
	int32 ResultDivide = CalcVarA / CalcVarB;
	FString StrResultDivide = FString::Printf(TEXT("%d"), ResultDivide);
	UKismetSystemLibrary::PrintString(
		this
		, StrResultDivide
		, true
		, true
		, FColor::Blue
		, Duration
		, TEXT("None"));

	// Divide(割り算)の処理(int > float)
	float ResultDivide2 = (float)CalcVarA / (float)CalcVarB;
	FString StrResultDivide2 = FString::Printf(TEXT("%f"), ResultDivide2);
	UKismetSystemLibrary::PrintString(
		this
		, StrResultDivide2
		, true
		, true
		, FColor::Blue
		, Duration
		, TEXT("None"));
}

void ACPPCalculation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

