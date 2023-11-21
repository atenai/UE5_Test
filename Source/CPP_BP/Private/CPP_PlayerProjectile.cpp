// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerProjectile.h"
#include "UObject/ConstructorHelpers.h"

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
}

void ACPP_PlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//画面横へ飛んでいくようにする
	MoveProjectile(FVector(0.0f, 400.0f, 0.0f), DeltaTime);
}