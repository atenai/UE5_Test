// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "CPP_BallPlayer.generated.h"

//Component��Class��O���錾(�v���g�^�C�v�錾)���܂��B
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

	//Ball���R���g���[������
	void ControlBall(const FInputActionValue& Value);

	//���_�𑀍삷��
	void Look(const FInputActionValue& Value);

	//�W�����v����i�@�֐����쐬����j
	void Jump(const FInputActionValue& Value);

	//Hit Event��Binding����֐�
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	//��������
	void Boost(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Player��Damage��^����
	float TakeDamagePlayer(const float Damage);

	//Player��Rebound������
	void Rebound(const float ReboundPower);

	//Player���񕜂�����
	float Heal(const float Value);

private:
	//�L�����N�^�[�p��StaticMesh : Sphere
	UPROPERTY(VisibleAnywhere, Category = Character, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Sphere;

	//Camera��z�u����ׂ�SpringArm
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	//SpringArm�̐�[�ɔz�u����J����
	UPROPERTY(VisibleAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> Camera;

	//���x
	float Speed = 300.0f;

	//�̗�
	float Health = 100.0f;

	//�ő�̗�
	float HealthMax = 100.0f;

	//MappingContext
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	//Control Input Action
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ControlAction;

	//Look Input Action
	UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;

	//�i�s������\������ArrowComponent
	UPROPERTY(VisibleAnywhere, Category = Control, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UArrowComponent> Arrow;

	//�W�����v�ɉ������
	float JumpImpluse = 500.0f;

	//�W�����v���ł��邩���肷��t���O
	bool CanJump = false;

	//Jump Input Action�i�B�C���v�b�g�����p�̃A�N�V�����ϐ����쐬����j
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	//�������鑁��
	float Torque = 500000000.0f;

	//Boost Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* BoostAction;
};
