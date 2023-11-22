// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CPP_EnemyPawn.generated.h"

UCLASS()
class CPP_BP_API ACPP_EnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACPP_EnemyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	class UStaticMeshComponent* StaticMeshComponent;

	float DirectionX;//�����o�ϐ��̒ǉ�

	UPROPERTY()
	TSubclassOf<class ACPP_EnemyProjectile> ProjectileClass;

	float RemainingShotTime;

	void ReloadProjectile();

	//�f���Q�[�g�ɓo�^����֐��́AUFUNCTION���K�{�ł�
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
