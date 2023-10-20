// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TrapFloor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "CPP_BallPlayer.h"
#include "Engine.h"

// Sets default values
ACPP_TrapFloor::ACPP_TrapFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponentを追加し、RootComponentに設定する
	TrapMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = TrapMesh;

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_TrapFloor"));

	// StaticMeshをStaticMeshComponentに設定する
	TrapMesh->SetStaticMesh(Mesh);

	// BoxComponentを追加し、BoxComponentをRootComponentにAttachする
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Box->SetupAttachment(RootComponent);

	// Boxのサイズを設定する
	Box->SetBoxExtent(FVector(50.0f, 50.0f, 20.0f));

	// Boxの位置を調整する
	Box->SetRelativeLocation(FVector(0.0f, 0.0f, 20.0f), false);

	// OnComponentBeginOverlapをBindする
	Box->OnComponentBeginOverlap.AddDynamic(this, &ACPP_TrapFloor::OnBoxBeginOverlap);
}

// Called when the game starts or when spawned
void ACPP_TrapFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_TrapFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_TrapFloor::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 接触したActorがBallPlayerか判定する
	if (ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(OtherActor))
	{
		//　PlayerをReboundさせる
		Player->Rebound(Rebound);

		// PlayerにDamageを与える
		float Health = Player->TakeDamagePlayer(Damage);

		UE_LOG(LogTemp, Display, TEXT("Health:%f"), Health);

		FString String = FString::FromInt(Health);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, String);
	}
}