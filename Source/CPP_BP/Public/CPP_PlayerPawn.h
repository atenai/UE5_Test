// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CPP_PlayerPawn.generated.h"

UCLASS(Blueprintable)
class CPP_BP_API ACPP_PlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	ACPP_PlayerPawn(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "PlayerMesh", meta = (AllowPrivateAccess = true))
	class UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION(BlueprintPure)
	FVector GetPlayerMoveDirection(float Direction) const;

private:
	void TestAddComponent(const FObjectInitializer& ObjectInitializer);
};
