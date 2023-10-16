// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_CheckPointActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "CPP_BallPlayer.h"
#include "CPP_InGameGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPP_CheckPointActor::ACPP_CheckPointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponent��ǉ����ARootComponent�ɐݒ肷��
	Checkpoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponentCheckpoint"));
	RootComponent = Checkpoint;

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* CheckpointMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_Checkpoint"));

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	Checkpoint->SetStaticMesh(CheckpointMesh);

	// StaticMeshComponent��ǉ����ARootComponent��Attach����
	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponentButton"));
	Button->SetupAttachment(RootComponent);

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* ButtonMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_CheckpointButton"));

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	Button->SetStaticMesh(ButtonMesh);

	// SphereCollision��ǉ�����
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootComponent);

	// Radius��ݒ肷��
	Sphere->SetSphereRadius(70.0f);

	// SceneComponent���쐬����
	CheckTransform = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	CheckTransform->SetupAttachment(RootComponent);

	// �����𒲐�����
	CheckTransform->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

	// OnComponentBeginOverlap��Bind����
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACPP_CheckPointActor::OnSphereBeginOverpal);
}

// Called when the game starts or when spawned
void ACPP_CheckPointActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_CheckPointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_CheckPointActor::OnSphereBeginOverpal(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �ڐG����Actor��BallPlayer�����肷��
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(OtherActor))
	{
		// GameMode���擾���āAInGameGameMode��Cast����
		if (ACPP_InGameGameMode* GameMode = Cast<ACPP_InGameGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			//�@CheckTransform��WorldTransform���擾����
			const FTransform& WorldTransform = CheckTransform->GetComponentToWorld();

			// Transform��񂪈�v���Ȃ�������Spawn����Transform�����X�V����
			if (!GameMode->SpawnTransform.Equals(WorldTransform))
			{
				// Respawn����Transform�����X�V����
				GameMode->SpawnTransform = WorldTransform;
			}
		}
	}
}