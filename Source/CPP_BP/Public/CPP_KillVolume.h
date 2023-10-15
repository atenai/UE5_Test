// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_KillVolume.generated.h"

class UBoxComponent;

UCLASS()
class CPP_BP_API ACPP_KillVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_KillVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ConstructionScript
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Box CollisionÇÃÉTÉCÉYÇê›íËÇ∑ÇÈïœêî
	UPROPERTY(EditAnywhere, Category = "Kill Volume")
	FVector BoxExtent = FVector(32.0f, 32.0f, 32.0f);

private:
	//Default Scene Root
	UPROPERTY(VisibleAnywhere, Category = KillVolume, meta = (AllowPrvateAccess = "true"))
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	//PlayerÇKillÇ∑ÇÈAreaÇê›íËÇ∑ÇÈBox Collision
	UPROPERTY(VisibleAnywhere, Category = KillVolume, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> KillVolume;

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
