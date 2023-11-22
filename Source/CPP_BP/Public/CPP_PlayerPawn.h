// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/DefaultPawn.h"
#include "Components/BoxComponent.h"
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

	//インプット用の関数を定義する②
	//virtual void AddControllerYawInput(float Val) override;

	UFUNCTION()
	void MouseMovePitchInput(float Val);

	void Fire();

	UPROPERTY()
	TSubclassOf<class ACPP_PlayerProjectile> ProjectileClass;

	//protectedにUPROPERTYをつけて当たり判定コンポーネントの変数を作成
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> Collider;

	//デリゲートに登録する関数は、UFUNCTIONが必須です
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

		UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	void TestAddComponent(const FObjectInitializer& ObjectInitializer);
};
