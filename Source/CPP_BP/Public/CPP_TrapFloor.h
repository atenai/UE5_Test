// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_TrapFloor.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class CPP_BP_API ACPP_TrapFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_TrapFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Trap�p��StaticMesh : TrapMesh
	UPROPERTY(VisibleAnywhere, Category = Trap , meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> TrapMesh;

	//Player��Damage��^����Box Collision : Box
	UPROPERTY(VisibleAnywhere, Category = Trap, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> Box;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Player�ɗ^����Damage
	UPROPERTY(EditAnywhere, Category = "Trap")
	float Damage = 25.0f;

	//Player��Rebound�����鋭��
	UPROPERTY(EditAnywhere, Category = "Trap")
	float Rebound = 600.0f;

private:
	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
