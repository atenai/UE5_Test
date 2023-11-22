// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EnemyProjectile.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine.h"
#include "Engine/World.h"

ACPP_EnemyProjectile::ACPP_EnemyProjectile() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("/Game/SM_EnemyProjectile.SM_EnemyProjectile"));
	if (StaticMeshComponent != nullptr && ProjectileMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(ProjectileMesh.Object);
	}

	if (StaticMeshComponent != nullptr)
	{
		//�G�f�B�^�̃v���W�F�N�g�ݒ�ɂ���R���W�����̍��ڂ�Preset�ɋL�ڂ��Ă���R���W�����̍��ڂ��X�^�e�B�b�N���b�V���ɃA�^�b�`����
		StaticMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	}

	//�����蔻��̃f���Q�[�g�Ɋ֐���o�^
	OnActorBeginOverlap.AddDynamic(this, &ACPP_EnemyProjectile::OnBeginOverlap);
}

void ACPP_EnemyProjectile::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("EnemyProjectileTrue"));

	MoveProjectile(FVector(0.0f, -200.0f, 0.0f), Deltatime);
}

void ACPP_EnemyProjectile::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//�����ɏՓ˂����Ƃ��̏���������
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("EnemyBullet"));
		//�����ɓ��������玩�g���폜
		World->DestroyActor(this);
	}
}