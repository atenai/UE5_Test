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

	//Trap—p‚ÌStaticMesh : TrapMesh
	UPROPERTY(VisibleAnywhere, Category = Trap , meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> TrapMesh;

	//Player‚ÉDamage‚ð—^‚¦‚éBox Collision : Box
	UPROPERTY(VisibleAnywhere, Category = Trap, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> Box;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Player‚É—^‚¦‚éDamage
	UPROPERTY(EditAnywhere, Category = "Trap")
	float Damage = 25.0f;

	//Player‚ðRebound‚³‚¹‚é‹­‚³
	UPROPERTY(EditAnywhere, Category = "Trap")
	float Rebound = 600.0f;

private:
	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
