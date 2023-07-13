// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bird.h"
#include "CPP_MyLibrary.h"
#include "Kismet/KismetMathLibrary.h"//追加
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
