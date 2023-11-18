// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EnemyPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

// Sets default values
ACPP_EnemyPawn::ACPP_EnemyPawn() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMeshObj(TEXT("/Game/SM_Enemy.SM_Enemy"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	if (StaticMeshComponent != nullptr && EnemyMeshObj.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(EnemyMeshObj.Object);
		RootComponent = StaticMeshComponent;
	}

	DirectionX = -1.0f;//コンストラクタで初期化

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_EnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_EnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector location = ((FVector(200.0f,0.0f,0.0f) * DeltaTime) * (FVector(1.0f,0.0f,0.0f) * DirectionX)) + GetActorLocation();

	SetActorLocation(location);
	if (300.0f < location.X)
	{
		DirectionX = -1.0f;
	}
	else if (location.X < -300.0f)
	{
		DirectionX = 1.0f;
	}
}

// Called to bind functionality to input
void ACPP_EnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

