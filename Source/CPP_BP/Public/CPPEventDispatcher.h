// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPCalcType.h"
#include "CPPEventDispatcher.generated.h"

// 1. delegateの宣言を追加する場合にはGlobalスコープに追加することが多いです。
// ここに追加


UCLASS()
class CPP_BP_API ACPPEventDispatcher : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPEventDispatcher();

	// Custom Event[PrintHello] 
	UFUNCTION()
		void PrintHello();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	int32 Sum(int32 A, int32 B);

	// Action Mappingsに設定したActionを処理する関数
	void PressedActionPrintCalcResult();

private:
	FString Message = "C++ Hello World!";

	// 計算結果を出力する関数
	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

	// PrintString関数のDurationに設定する変数
	const float Duration = 10.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FColor(255, 255, 255);

	// 計算用の変数
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control用の変数
	bool IsPrintHello = false;
	ECPPCalcType CalcType = ECPPCalcType::Add;

	// Input設定
	void SetupInput();

	// Input Eventを処理する関数
	void PressedH();

public:
	// 2. class内でdelegateの宣言を書くことも可能で
	// Blueprint連携する場合にはこちらに書くことが多いです
	// ここに追加

	// Event Dispatcher[OnPrintHello]
	// DECLARE_DYNAMIC_MULTICAST_DELEGATEに関してはBlueprintと連携可能
	//DECLARE_DYNAMIC_MULTICAST_DELEGATE(デリゲートの型名);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrintHelloDelegate);

	// Blueprintからアサイン可能にするためにBlueprintAssignableを付与する
	UPROPERTY(BlueprintAssignable, Category = "CPP_BP")
		FPrintHelloDelegate OnPrintHello;//上で作成したFPrintHelloDelegateのデリゲート型のOnPrintHelloデリゲートを作成する

};
