// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerProjectile.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "CPP_EnemyPawn.h"
#include "CPP_EnemyProjectile.h"

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

	//�����蔻��̃f���Q�[�g�Ɋ֐���o�^
	OnActorBeginOverlap.AddDynamic(this, &ACPP_PlayerProjectile::OnBeginOverlap);

	Tags.AddUnique(TEXT("PlayerType"));
}

void ACPP_PlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//��ʉ��֔��ł����悤�ɂ���
	MoveProjectile(FVector(0.0f, 400.0f, 0.0f), DeltaTime);
}

void ACPP_PlayerProjectile::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//�����ɏՓ˂����Ƃ��̏���������
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		if(OtherActor != nullptr)
		{
			//�G���G�̒e�ɓ��������Ƃ����������ł�����
			//if(OtherActor->IsA<ACPP_EnemyPawn>() || OtherActor->IsA<ACPP_EnemyProjectile>())
			if(OtherActor->ActorHasTag(TEXT("EnemyType")))
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("PlayerBullet"));
				//�����ɓ��������玩�g���폜
				World->DestroyActor(this);
			}
		}
	}
}