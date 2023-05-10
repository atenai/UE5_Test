// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVariable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // 追加

ACPPVariable::ACPPVariable()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPVariable::BeginPlay()
{
	Super::BeginPlay();

	// 変数を作成する
	FString Message = "Variable";

	// Durationに別の値を設定する
	//Duration = 30.0f;

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Yellow, Duration, TEXT("None"));
	
	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(
		this
		, UKismetStringLibrary::Conv_DoubleToString(Duration) // DurationをfloatからFStringに変換する
		, true
		, true
		, TextColor
		, Duration
		, TEXT("None"));
}

void ACPPVariable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

