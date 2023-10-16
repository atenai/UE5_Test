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

	// StaticMeshComponentを追加し、RootComponentに設定する
	Checkpoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponentCheckpoint"));
	RootComponent = Checkpoint;

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* CheckpointMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_Checkpoint"));

	// StaticMeshをStaticMeshComponentに設定する
	Checkpoint->SetStaticMesh(CheckpointMesh);

	// StaticMeshComponentを追加し、RootComponentにAttachする
	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponentButton"));
	Button->SetupAttachment(RootComponent);

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* ButtonMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_CheckpointButton"));

	// StaticMeshをStaticMeshComponentに設定する
	Button->SetStaticMesh(ButtonMesh);

	// SphereCollisionを追加する
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootComponent);

	// Radiusを設定する
	Sphere->SetSphereRadius(70.0f);

	// SceneComponentを作成する
	CheckTransform = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	CheckTransform->SetupAttachment(RootComponent);

	// 高さを調整する
	CheckTransform->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

	// OnComponentBeginOverlapをBindする
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
	// 接触したActorがBallPlayerか判定する
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(OtherActor))
	{
		// GameModeを取得して、InGameGameModeにCastする
		if (ACPP_InGameGameMode* GameMode = Cast<ACPP_InGameGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			//　CheckTransformのWorldTransformを取得する
			const FTransform& WorldTransform = CheckTransform->GetComponentToWorld();

			// Transform情報が一致しなかったらSpawnするTransform情報を更新する
			if (!GameMode->SpawnTransform.Equals(WorldTransform))
			{
				// RespawnするTransform情報を更新する
				GameMode->SpawnTransform = WorldTransform;
			}
		}
	}
}