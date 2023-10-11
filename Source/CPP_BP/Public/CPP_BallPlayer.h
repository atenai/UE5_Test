// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "CPP_BallPlayer.generated.h"

//ComponentのClassを前方宣言(プロトタイプ宣言)します。
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UArrowComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class CPP_BP_API ACPP_BallPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACPP_BallPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Ballをコントロールする
	void ControlBall(const FInputActionValue& Value);

	//視点を操作する
	void Look(const FInputActionValue& Value);

	//ジャンプする
	void Jump(const FInputActionValue& Value);

	//Hit EventをBindingする関数
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//キャラクター用のStaticMesh : Sphere
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Sphere;

	//Cameraを配置する為のSpringArm
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	//SpringArmの先端に配置するカメラ
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> Camera;

	//速度
	float Speed = 300.0f;

	//体力
	float Health = 100.0f;

	//MappingContext
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	//Control Input Action
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ControlAction;

	//Look Input Action
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;

	//進行方向を表示するArrowComponent
	UPROPERTY(VisibleAnywhere, Category = Control, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UArrowComponent> Arrow;

	//ジャンプに加える力
	float JumpImpluse = 500.0f;

	//ジャンプができるか判定するフラグ
	bool CanJump = false;

	//Jump Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;
};
