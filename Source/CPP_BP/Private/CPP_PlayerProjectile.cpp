// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerProjectile.h"
#include "UObject/ConstructorHelpers.h"

ACPP_PlayerProjectile::ACPP_PlayerProjectile() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("/Game/SM_PlayerProjectile.SM_PlayerProjectile"));

	if (StaticMeshComponent != nullptr && ProjectileMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(ProjectileMesh.Object);
	}

	if (StaticMeshComponent != nullptr)
	{
		//�G�f�B�^�̃v���W�F�N�g�ݒ�ɂ���R���W�����̍��ڂ�Preset�ɋL�ڂ��Ă���R���W�����̍��ڂ��X�^�e�B�b�N���b�V���ɃA�^�b�`����
		StaticMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	}
}

void ACPP_PlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//��ʉ��֔��ł����悤�ɂ���
	MoveProjectile(FVector(0.0f, 400.0f, 0.0f), DeltaTime);
}