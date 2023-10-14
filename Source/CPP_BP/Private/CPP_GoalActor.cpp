// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_GoalActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "CPP_BallPlayer.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPP_GoalActor::ACPP_GoalActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponent��ǉ����ARootComponent�ɐݒ肷��
	Goal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Goal;

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_Goal"));

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	Goal->SetStaticMesh(Mesh);

	// SphereCollision��ǉ�����
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootComponent);

	// Radius��ݒ肷��
	Sphere->SetSphereRadius(72.0f);

	// OnComponentBeginOverlap��Bind����
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACPP_GoalActor::OnSphereBeginOverlap);
}

// Called when the game starts or when spawned
void ACPP_GoalActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_GoalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_GoalActor::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �ڐG����Actor��BallPlayer�����肷��
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(OtherActor))
	{
		//�A�E�g�v�b�g���O�Ƀ��b�Z�[�W��\������
		UE_LOG(LogTemp, Display, TEXT("Goal"));
		//�X�N���[���Ƀ��b�Z�[�W��\������
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Goal"));
		// �J�ڂ���Level��Load����
		UGameplayStatics::OpenLevelBySoftObjectPtr(this, LoadLevel);
	}
}