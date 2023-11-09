// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

ACPP_PlayerPawn::ACPP_PlayerPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//TestAddComponent(ObjectInitializer);
	StaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMesh"));
	if (StaticMeshComponent != nullptr)
	{
		RootComponent = StaticMeshComponent;
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlayerMeshObj(TEXT("/Game/SM_Player.SM_Player"));
	//初期のStaticMeshにセット
	if (ensure(PlayerMeshObj.Succeeded()))
	{
		StaticMeshComponent->SetStaticMesh(PlayerMeshObj.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_PlayerPawn::TestAddComponent(const FObjectInitializer& ObjectInitializer)
{
	// USceneComponent を RootComponent にする
	USceneComponent* NewRootSceneComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("NewRootComponent"));
	if (NewRootSceneComponent != nullptr)
	{
		RootComponent = NewRootSceneComponent;
	}

	// UStaticMeshComponent のアタッチ
	StaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMeshTest"));
	if (StaticMeshComponent != nullptr)
	{
		StaticMeshComponent->SetupAttachment(RootComponent);
	}
}

FVector ACPP_PlayerPawn::GetPlayerMoveDirection(float Direction) const
{
	return (FVector(10.0f,0.0f,0.0f) * Direction) + GetActorLocation();
}