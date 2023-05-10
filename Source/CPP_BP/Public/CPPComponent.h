// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ArrowComponent.h" // í«â¡
#include "Components/PointLightComponent.h" // í«â¡

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
	// PrintStringä÷êîÇÃDurationÇ…ê›íËÇ∑ÇÈïœêî
	const float Duration = 10.0f;

	// PrintStringä÷êîÇÃTextColorÇ…ê›íËÇ∑ÇÈïœêî
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);
};
