// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EnemyProjectile.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine.h"
#include "Engine/World.h"

ACPP_EnemyProjectile::ACPP_EnemyProjectile() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("/Game/SM_EnemyProjectile.SM_EnemyProjectile"));
	if (StaticMeshComponent != nullptr && ProjectileMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(ProjectileMesh.Object);
	}

	if (StaticMeshComponent != nullptr)
	{
		//エディタのプロジェクト設定にあるコリジョンの項目のPresetに記載してあるコリジョンの項目をスタティックメッシュにアタッチする
		StaticMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	}

	//あたり判定のデリゲートに関数を登録
	OnActorBeginOverlap.AddDynamic(this, &ACPP_EnemyProjectile::OnBeginOverlap);
}

void ACPP_EnemyProjectile::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("EnemyProjectileTrue"));

	MoveProjectile(FVector(0.0f, -200.0f, 0.0f), Deltatime);
}

void ACPP_EnemyProjectile::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//ここに衝突したときの処理を書く
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("EnemyBullet"));
		//何かに当たったら自身を削除
		World->DestroyActor(this);
	}
}