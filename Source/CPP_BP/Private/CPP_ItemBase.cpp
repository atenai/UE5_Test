// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ItemBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "CPP_BallPlayer.h"

// Sets default values
ACPP_ItemBase::ACPP_ItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponent��ǉ����ARootComponent�ɐݒ肷��
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = ItemMesh;

	// SphereCollision��ǉ�����
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootComponent);

	// Radius��ݒ肷��
	Sphere->SetSphereRadius(50.0f);

	//�B�����蔻��̊֐���R�Â���
	// OnComponentBeginOverlap��Bind����
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACPP_ItemBase::OnSphereBeginOverlap);

	// RotatingMovementComponent��ǉ�����
	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovementComponent"));
	RotatingMovement->SetUpdatedComponent(ItemMesh);
}

// Called when the game starts or when spawned
void ACPP_ItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_ItemBase::GetItem()
{
	// �����͎q�N���X�Ōp�����Ď�������
}

//�A�����蔻��p�̊֐��̒��g���쐬����
void ACPP_ItemBase::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �ڐG����Actor��BallPlayer�����肷��
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(OtherActor))
	{
		// Item���擾���鏈������������
		this->GetItem();

		// �A�C�e����j������
		this->Destroy();
	}
}