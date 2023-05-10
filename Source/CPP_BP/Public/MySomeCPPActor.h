// Fill out your copyright notice in the Description page of Project Settings.//消すと壊れる

#pragma once//消すと壊れる

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySomeCPPActor.generated.h"//.generated.hがついた奴は必ず一番最後にする必要がある

UCLASS()
class CPP_BP_API AMySomeCPPActor : public AActor
{
	GENERATED_BODY()
	
public:	
    //コンストラクタ、これを消すと壊れる
	AMySomeCPPActor();

protected:
    //スタート関数
	virtual void BeginPlay() override;

private:
    //変数

    float num10 = 10.0f;


public:	
    //アップデート関数
	virtual void Tick(float DeltaTime) override;


    static const int year = 2023;

    //関数

    //UFUNCTION(Unreal関数の意味)をつける事でその直後に宣言された関数をアンリアルエンジン内のブループリントエディタから設定できるようになります。
    //第一引数はBlueprintCallableとBlueprintPureがある
    //BlueprintCallableは処理のInputとOutputの入口と出口があるノードになる
    //BlueprintPureは値だけを持つノードになる(純粋化)
    //第二引数のCategory = "TestC++"は「 "TestC++"」の部分は自由に名前をつけることができ、その名前のカテゴリーに関数が作られる
    UFUNCTION(BlueprintCallable, Category = "TestC++")
        void TestPrint();

    //BlueprintCallableは処理のInputとOutputの入口と出口があるノードになる
    UFUNCTION(BlueprintCallable, Category = "TestC++")
        static int StaticSetAddNumber(int number);//staticをつけるとどのブループリントからも呼び出せる

    //BlueprintPureは値だけを持つノードになる(純粋化)
    UFUNCTION(BlueprintPure, Category = "TestC++")
        static int StaticGet2023();

    UFUNCTION(BlueprintPure, Category = "TestC++")
        float Get10();
};