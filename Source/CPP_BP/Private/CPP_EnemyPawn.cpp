// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EnemyPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "CPP_EnemyProjectile.h"
#include "Particles/ParticleSystem.h"
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

	if (StaticMeshComponent != nullptr)
	{
		//エディタのプロジェクト設定にあるコリジョンの項目のPresetに記載してあるコリジョンの項目をスタティックメッシュにアタッチする
		StaticMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	}

	DirectionX = -1.0f;//コンストラクタで初期化

	static ConstructorHelpers::FClassFinder<ACPP_EnemyProjectile> EnemyProjectileClass(TEXT("/Game/Blueprints/BP_EnemyProjectile.BP_EnemyProjectile_C"));
	if (EnemyProjectileClass.Succeeded())
	{
		ProjectileClass = EnemyProjectileClass.Class;
	}

	RemainingShotTime = 0.0f;

	//あたり判定のデリゲートに関数を登録
	OnActorBeginOverlap.AddDynamic(this, &ACPP_EnemyPawn::OnBeginOverlap);

	//コンストラクタ内に追加実装
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ExplosionParticleObj(TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));
	if (ExplosionParticleObj.Succeeded())
	{
		ExplosionParticle = ExplosionParticleObj.Object;
	}

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
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("EnemyPawnTrue"));
			FRotator SpawnRotator = FRotator::ZeroRotator;
			FVector SpawnLocation = GetActorLocation() + FVector(0.0f, -100.0f, 0.0f);//少し離れて出す
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			World->SpawnActor<ACPP_EnemyProjectile>(ProjectileClass, SpawnLocation, SpawnRotator, SpawnParams);
		}
		ReloadProjectile();
	}
}

void ACPP_EnemyPawn::ReloadProjectile()
{
	//次の弾を撃つ時間を設定
	RemainingShotTime = FMath::RandRange(1.0f, 2.0f);
}

void ACPP_EnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPP_EnemyPawn::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//ここに衝突したときの処理を書く
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, TEXT("Enemy"));

	EffectInstance();
}

void ACPP_EnemyPawn::EffectInstance()
{
	//RootComponentにExplosionParticleをアタッチして生成
	UGameplayStatics::SpawnEmitterAttached(ExplosionParticle, GetRootComponent(), NAME_None, FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);
}