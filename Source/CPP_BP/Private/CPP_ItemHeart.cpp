// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ItemHeart.h"
#include "CPP_BallPlayer.h"//アクセスしたいクラスのヘッダーをインクルード
#include "Kismet/GameplayStatics.h"//他のアクターを探す為に必要なヘッダーをインクルード
#include "Engine.h"

ACPP_ItemHeart::ACPP_ItemHeart()
{
	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/RollingBall/Items/Meshes/S_Heart"), NULL, LOAD_None, NULL);

	// StaticMeshをStaticMeshComponentに設定する
	ItemMesh->SetStaticMesh(Mesh);
}

void ACPP_ItemHeart::GetItem()
{
	// BallPlayerを取得する
	if (ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(),0)))
	{
		// Playerを回復する
		float Health = Player->Heal(HealValue);

		UE_LOG(LogTemp, Display, TEXT("Health:%f"), Health);

		FString String = FString::FromInt(Health);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, String);
	}
}