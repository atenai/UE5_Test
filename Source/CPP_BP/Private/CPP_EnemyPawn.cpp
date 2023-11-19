// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EnemyPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "CPP_EnemyProjectile.h"
#include "Engine.h"

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

	/*static ConstructorHelpers::FClassFinder<ACPP_EnemyProjectile> EnemyProjectileClass(TEXT("/Game/Blueprints/BP_EnemyProjectile.BP_EnemyProjectile_C"));
	if (EnemyProjectileClass.Succeeded())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("True"));
		ProjectileClass = EnemyProjectileClass.Class;
	}*/

	RemainingShotTime = 0.0f;

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

	RemainingShotTime -= DeltaTime;
	if (RemainingShotTime <= 0.0f)
	{
		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EnemyFireTrue"));
			FRotator SpawnRotator = FRotator::ZeroRotator;
			FVector SpawnLocation = GetActorLocation() + FVector(0.0f, -50.0f, 0.0f);//少し離れて出す
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			//iWorld->SpawnActor<ACPP_EnemyProjectile>(ProjectileClass, SpawnLocation, SpawnRotator, SpawnParams);
		}
		ReloadProjectile();
	}
}

void ACPP_EnemyPawn::ReloadProjectile()
{
	//次の弾を撃つ時間を設定
	RemainingShotTime = FMath::RandRange(1.0f, 2.0f);
}

// Called to bind functionality to input
void ACPP_EnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

