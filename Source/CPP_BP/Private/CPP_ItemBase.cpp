// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ItemBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "CPP_BallPlayer.h"

// Sets default values
ACPP_ItemBase::ACPP_ItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponentを追加し、RootComponentに設定する
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = ItemMesh;

	// SphereCollisionを追加する
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootComponent);

	// Radiusを設定する
	Sphere->SetSphereRadius(50.0f);

	//③当たり判定の関数を紐づける
	// OnComponentBeginOverlapをBindする
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACPP_ItemBase::OnSphereBeginOverlap);

	// RotatingMovementComponentを追加する
	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovementComponent"));
	RotatingMovement->SetUpdatedComponent(ItemMesh);
}

// Called when the game starts or when spawned
void ACPP_ItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_ItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_ItemBase::GetItem()
{
	// 処理は子クラスで継承して実装する
}

//②当たり判定用の関数の中身を作成する
void ACPP_ItemBase::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 接触したActorがBallPlayerか判定する
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(OtherActor))
	{
		// Itemを取得する処理を実装する
		this->GetItem();

		// アイテムを破棄する
		this->Destroy();
	}
}