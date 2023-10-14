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

	// StaticMeshComponentを追加し、RootComponentに設定する
	Goal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Goal;

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_Goal"));

	// StaticMeshをStaticMeshComponentに設定する
	Goal->SetStaticMesh(Mesh);

	// SphereCollisionを追加する
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootComponent);

	// Radiusを設定する
	Sphere->SetSphereRadius(72.0f);

	// OnComponentBeginOverlapをBindする
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
	// 接触したActorがBallPlayerか判定する
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(OtherActor))
	{
		//アウトプットログにメッセージを表示する
		UE_LOG(LogTemp, Display, TEXT("Goal"));
		//スクリーンにメッセージを表示する
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Goal"));
		// 遷移するLevelをLoadする
		UGameplayStatics::OpenLevelBySoftObjectPtr(this, LoadLevel);
	}
}