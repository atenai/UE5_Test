// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_ItemBase.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class URotatingMovementComponent;

UCLASS()
class CPP_BP_API ACPP_ItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_ItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Item�p��StaticMesh : ItemMesh
	UPROPERTY(VisibleAnywhere, Category = Item)
	TObjectPtr<UStaticMeshComponent> ItemMesh;

	//�ڐG����p��Collision : Sphere
	UPROPERTY(VisibleAnywhere, Category = Item)
	TObjectPtr<USphereComponent> Sphere;

	//��]�p��Component
	UPROPERTY(VisibleAnywhere, Category = Item)
	TObjectPtr<URotatingMovementComponent> RotatingMovement;

	//Item�擾�p�̊֐�
	virtual void GetItem();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//�@�����蔻��̊֐����쐬����
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
