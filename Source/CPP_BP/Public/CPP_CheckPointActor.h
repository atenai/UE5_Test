// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_CheckPointActor.generated.h"

class UStaticMeshComponent;
class USphereComponent;

UCLASS()
class CPP_BP_API ACPP_CheckPointActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_CheckPointActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Checkpoint用のStaticMesh : Checkpoint
	UPROPERTY(VisibleAnywhere, Category = Checkpoint, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Checkpoint;

	//Checkpoint用のStaticMesh : Button
	UPROPERTY(VisibleAnywhere, Category = Checkpoint, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Button;

	//接触判定用のCollision : Sphere
	UPROPERTY(VisibleAnywhere, Category = Checkpoint, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> Sphere;

	//Respawn用のTransformを更新するSceneComponent
	UPROPERTY(VisibleAnywhere, Category = Checkpoint, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> CheckTransform;
};
