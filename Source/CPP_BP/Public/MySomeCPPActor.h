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
    UFUNCTION(BlueprintCallable, Category = "KashiwabaraC++")
    void TestPrint(int testNumber);

    //BlueprintCallableは処理のInputとOutputの入口と出口があるノードになる
    UFUNCTION(BlueprintCallable, Category = "KashiwabaraC++")
    static int StaticSetAddNumber(int number);//staticをつけるとどのブループリントからも呼び出せる

    //BlueprintPureは値だけを持つノードになる(純粋化)
    UFUNCTION(BlueprintPure, Category = "KashiwabaraC++")
    static int StaticGet2023();

    UFUNCTION(BlueprintPure, Category = "KashiwabaraC++")
    float Get10();

	UPROPERTY(EditAnywhere)
    float num10 = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Reference|Edit")
	float NumEditAnywhere;

	UPROPERTY(EditDefaultsOnly, Category = "Reference|Edit")
	float NumEditDefaultsOnly;

	UPROPERTY(EditInstanceOnly, Category = "Reference|Edit")
	float NumEditInstanceOnly;

	UPROPERTY(VisibleAnywhere, Category = "Reference|Visible")
	float NumVisibleAnywhere;

	UPROPERTY(VisibleDefaultsOnly, Category = "Reference|Visible")
	float NumVisibleDefaultsOnly;

	UPROPERTY(VisibleInstanceOnly, Category = "Reference|Visible")
	float NumVisibleInstanceOnly;

    UPROPERTY(EditAnywhere, meta = (EditCondition = "bEditCondition"), Category = "Reference|Edit")
	float NumEditCondition;

	UPROPERTY()
	bool bEditCondition;
    
    UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "Reference")
	float NumAdvancedDisplay;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ReadWrite")
	float NumBlueprintReadOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ReadWrite")
	float NumBlueprintReadWrite;

    /* Description String */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Description")
	float NumDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "-10.0", ClampMax = "10.0"), Category = "ValueRange")
	float NumValueRange;
};