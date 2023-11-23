// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainGameProjectile.h"

// Sets default values
ACPP_MainGameProjectile::ACPP_MainGameProjectile() :Super()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMeshComponent;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_MainGameProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(3.0f);//3秒でDestroyする
}

// Called every frame
void ACPP_MainGameProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_MainGameProjectile::MoveProjectile(const FVector& Direction, float DeltaTime)
{
	//このオブジェクトの座標をセットする（方向 × 時間）+ 現在地
	SetActorLocation((Direction * DeltaTime) + GetActorLocation());
}