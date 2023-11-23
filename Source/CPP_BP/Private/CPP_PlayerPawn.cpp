// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "CPP_PlayerProjectile.h"
#include "Engine/World.h"
#include "Engine.h"

ACPP_PlayerPawn::ACPP_PlayerPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//TestAddComponent(ObjectInitializer);
	StaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMesh"));
	if (StaticMeshComponent != nullptr)
	{
		RootComponent = StaticMeshComponent;
	}

	if (StaticMeshComponent != nullptr)
	{
		//エディタのプロジェクト設定にあるコリジョンの項目のPresetに記載してあるコリジョンの項目をスタティックメッシュにアタッチする
		StaticMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlayerMeshObj(TEXT("/Game/SM_Player.SM_Player"));
	//初期のStaticMeshにセット
	if (ensure(PlayerMeshObj.Succeeded()))
	{
		StaticMeshComponent->SetStaticMesh(PlayerMeshObj.Object);
	}

	//ブループリントクラスを取得
	static ConstructorHelpers::FClassFinder<ACPP_PlayerProjectile> PlayerProjectileClass(TEXT("/Game/Blueprints/BP_PlayerProjectile.BP_PlayerProjectile_C"));
	//↑で取得したブループリントクラスをProjectileClassに保持しておく
	if (PlayerProjectileClass.Succeeded())
	{
		ProjectileClass = PlayerProjectileClass.Class;
	}

	//コンストラクタ内に追加
	static ConstructorHelpers::FClassFinder<AActor> PlayerExplosionClass(TEXT("/Game/StarterContent/Blueprints/Blueprint_Effect_Explosion.Blueprint_Effect_Explosion_C"));
	if (PlayerExplosionClass.Succeeded())
	{
		ExplosionClass = PlayerExplosionClass.Class;
	}

	// BoxComponentを追加し、BoxComponentをRootComponentにAttachする
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	Collider->SetupAttachment(RootComponent);

	// Boxのサイズを設定する
	Collider->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));

	// Boxの位置を調整する
	Collider->SetRelativeLocation(FVector(0.0f, 0.0f, 20.0f), false);

	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACPP_PlayerPawn::OnBoxBeginOverlap);

	//あたり判定のデリゲートに関数を登録
	this->OnActorBeginOverlap.AddDynamic(this, &ACPP_PlayerPawn::OnBeginOverlap);

	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//インプット用の初期化処理の関数を作成する①
//void InitializeDefaultPawnInputBindings()
//{
//	static bool bBindingsAdded = false;
//	if (!bBindingsAdded)
//	{
//		bBindingsAdded = true;
//		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_Turn", EKeys::MouseY, 1.0f));
//	}
//}

//インプット用の関数を作成する③
//void ACPP_PlayerPawn::AddControllerYawInput(float Val)
//{
//	Super::AddControllerYawInput(Val);
//
//	//マウスに合わせて移動させる
//	SetActorLocation(GetPlayerMoveDirection(Val));
//}

void ACPP_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//ここでインプット用の処理を初期化する関数を呼んでから↑で作成したインプット用の関数をバインドする④
	//InitializeDefaultPawnInputBindings();
	//PlayerInputComponent->BindAxis("DefaultPawn_Turn", this, &ACPP_PlayerPawn::AddControllerYawInput);
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

void ACPP_PlayerPawn::MouseMovePitchInput(float Val)
{
	SetActorLocation(GetPlayerMoveDirection(Val));
}

void ACPP_PlayerPawn::Fire()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Fire3"));
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Fire4"));
		FRotator SpawnRotator = FRotator::ZeroRotator;//ちゃんと初期化しないと回転が安定しない
		FVector SpawnLocation = GetActorLocation() + FVector(0.0f,100.0f,0.0f);//自機より少し横に出す
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		//TSubclassOf<ACPP_PlayerProjectile> ProjectileLoadedClass = StaticLoadClass(ACPP_PlayerProjectile::StaticClass(), nullptr, TEXT("/Game/Blueprints/BP_PlayerProjectile.BP_PlayerProjectile_C"));
		//World->SpawnActor<ACPP_PlayerProjectile>(ProjectileLoadedClass, SpawnLocation, SpawnRotator, SpawnParams);//SpawnActor関数を使⽤することで、Actor を⽣成することができます。

		World->SpawnActor<ACPP_PlayerProjectile>(ProjectileClass, SpawnLocation, SpawnRotator, SpawnParams);//SpawnActor関数を使⽤することで、Actor を⽣成することができます。
	}

	//EffectInstance();
	//TestActorInstance();
}

void ACPP_PlayerPawn::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//ここに衝突したときの処理を書く
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Player1"));

	EffectInstance();
}

void ACPP_PlayerPawn::EffectInstance()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Effect"));
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		FRotator SpawnRotator = FRotator::ZeroRotator;//ちゃんと初期化しないと回転が安定しない
		FVector SpawnLocation = GetActorLocation();
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		World->SpawnActor<AActor>(ExplosionClass, SpawnLocation, SpawnRotator, SpawnParams);
	}
}

void ACPP_PlayerPawn::TestActorInstance()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("TestActorInstance"));
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		FRotator SpawnRotator = FRotator::ZeroRotator;//ちゃんと初期化しないと回転が安定しない
		FVector SpawnLocation = GetActorLocation() + FVector(0.0f, 100.0f, 0.0f);//自機より少し横に出す
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		TSubclassOf<AActor> ProjectileLoadedClass = StaticLoadClass(AActor::StaticClass(), nullptr, TEXT("/Game/Blueprints/BP_TestActor.BP_TestActor_C"));
		World->SpawnActor<AActor>(ProjectileLoadedClass, SpawnLocation, SpawnRotator, SpawnParams);//SpawnActor関数を使⽤することで、Actor を⽣成することができます。
	}
}

void ACPP_PlayerPawn::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//ここに衝突したときの処理を書く
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("Player2"));
}