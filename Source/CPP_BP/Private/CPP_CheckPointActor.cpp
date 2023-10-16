// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_CheckPointActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ACPP_CheckPointActor::ACPP_CheckPointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponent‚ğ’Ç‰Á‚µARootComponent‚Éİ’è‚·‚é
	Checkpoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponentCheckpoint"));
	RootComponent = Checkpoint;

	// StaticMesh‚ğLaod‚µ‚ÄStaticMeshComponent‚ÌStaticMesh‚Éİ’è‚·‚é
	UStaticMesh* CheckpointMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_Checkpoint"));

	// StaticMesh‚ğStaticMeshComponent‚Éİ’è‚·‚é
	Checkpoint->SetStaticMesh(CheckpointMesh);

	// StaticMeshComponent‚ğ’Ç‰Á‚µARootComponent‚ÉAttach‚·‚é
	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponentButton"));
	Button->SetupAttachment(RootComponent);

	// StaticMesh‚ğLaod‚µ‚ÄStaticMeshComponent‚ÌStaticMesh‚Éİ’è‚·‚é
	UStaticMesh* ButtonMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_CheckpointButton"));

	// StaticMesh‚ğStaticMeshComponent‚Éİ’è‚·‚é
	Button->SetStaticMesh(ButtonMesh);

	// SphereCollision‚ğ’Ç‰Á‚·‚é
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootComponent);

	// Radius‚ğİ’è‚·‚é
	Sphere->SetSphereRadius(70.0f);

	// SceneComponent‚ğì¬‚·‚é
	CheckTransform = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	CheckTransform->SetupAttachment(RootComponent);

	// ‚‚³‚ğ’²®‚·‚é
	CheckTransform->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
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

