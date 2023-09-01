// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bird.h"//追加
#include "CPP_MyLibrary.h"//追加
#include "Kismet/KismetMathLibrary.h"//追加
#include "Kismet/KismetSystemLibrary.h"//追加
#include "Components/ArrowComponent.h"//追加
#include "Components/PointLightComponent.h"//追加
#include "CPP_MyStruct.h"//追加
#include "CPP_MyActor.generated.h"

UCLASS()
class CPP_BP_API ACPP_MyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_MyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform& Transform) override;

	// オブジェクトを配置する基礎部分であるデフォルトシーンルート
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	// UE5 の場合（推奨） 
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly) 
	TObjectPtr<UStaticMeshComponent> Comp;

	//メンバ変数の定義
	UPROPERTY(EditAnywhere)
	double Var = 1.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Param",meta = (ClampMin = 0.0f, ClampMax = 1000.0f ))
	double testUPROPERTY = 1.0f;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Function"))
	void Func(double In1, double In2, double& Out1, double& Out2);

	UFUNCTION(BlueprintCallable)
	void Func2(double In1, bool isIn2);

	double MemberVar = 0.0f;
	double ParentMemberVar = 0.0f;
	double MemberVar1 = 0.0f;
	bool MemberVar2 = true;
	double MemVar1 = 10.0f;
	double MemVar2 = 20.0f;

	UFUNCTION(BlueprintCallable)
	void Func3();

public:
	UPROPERTY(EditAnywhere)
	double PublicVar;//publicのメンバ変数

	UFUNCTION(BlueprintCallable)
	int32 PublicFunc();//publicのメンバ関数

protected:
	UPROPERTY(EditAnywhere)
	int32 ProtectedVar;//protectedのメンバ変数

	UFUNCTION(BlueprintCallable)
	void ProtectedFunc();//protectedのメンバ関数
};
