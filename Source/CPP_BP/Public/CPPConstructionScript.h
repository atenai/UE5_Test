// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/PointLightComponent.h"
#include "CPPConstructionScript.generated.h"

UCLASS()
class CPP_BP_API ACPPConstructionScript : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPConstructionScript();

	// Scene Component
	UPROPERTY(EditAnywhere)
		TObjectPtr<USceneComponent> DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> StaticMesh;

	// Arrow Component
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UArrowComponent> Arrow;

	// PointLightComponent Component
	UPROPERTY(EditAnywhere)
		TObjectPtr<UPointLightComponent> PointLight;

	//変数の追加
	UPROPERTY(EditAnywhere, Category = "Point Light")
		bool bIsVisible = false;

	//変数の追加
	UPROPERTY(EditAnywhere, Category = "Point Light")
		float Intensity = 5000.0f;

	//変数の追加
	UPROPERTY(EditAnywhere, Category = "Point Light")
		FLinearColor LightColor = FLinearColor::White;

protected:
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	// PrintString関数のDurationに設定する変数
	const float Duration = 10.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);
};
