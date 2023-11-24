// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerProjectile.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "CPP_EnemyPawn.h"
#include "CPP_EnemyProjectile.h"

ACPP_PlayerProjectile::ACPP_PlayerProjectile() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("/Game/SM_PlayerProjectile.SM_PlayerProjectile"));

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
	OnActorBeginOverlap.AddDynamic(this, &ACPP_PlayerProjectile::OnBeginOverlap);

	Tags.AddUnique(TEXT("PlayerType"));
}

void ACPP_PlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//画面横へ飛んでいくようにする
	MoveProjectile(FVector(0.0f, 400.0f, 0.0f), DeltaTime);
}

void ACPP_PlayerProjectile::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	//ここに衝突したときの処理を書く
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		if(OtherActor != nullptr)
		{
			//敵か敵の弾に当たったとき自分を消滅させる
			//if(OtherActor->IsA<ACPP_EnemyPawn>() || OtherActor->IsA<ACPP_EnemyProjectile>())
			if(OtherActor->ActorHasTag(TEXT("EnemyType")))
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("PlayerBullet"));
				//何かに当たったら自身を削除
				World->DestroyActor(this);
			}
		}
	}
}