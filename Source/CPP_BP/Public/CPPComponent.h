// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ArrowComponent.h" // 追加
#include "Components/PointLightComponent.h" // 追加

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPComponent.generated.h"

UCLASS()
class CPP_BP_API ACPPComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

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

private:
	// PrintString関数のDurationに設定する変数
	const float Duration = 10.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);
};
