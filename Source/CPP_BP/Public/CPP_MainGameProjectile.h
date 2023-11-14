// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_MainGameProjectile.generated.h"

UCLASS()
class CPP_BP_API ACPP_MainGameProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_MainGameProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION()
	void MoveProjectile(const FVector& Direction, float DeltaTime);

private:
	
};
