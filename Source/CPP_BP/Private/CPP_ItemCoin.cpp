// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ItemCoin.h"
#include "CPP_InGameGameMode.h"
#include "Kismet/GameplayStatics.h"

ACPP_ItemCoin::ACPP_ItemCoin()
{
	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Items/Meshes/S_Coin"));

	// StaticMeshをStaticMeshComponentに設定する
	ItemMesh->SetStaticMesh(Mesh);
}

void ACPP_ItemCoin::GetItem()
{
	// GameModeを取得して、InGameGameModeにCastする
	if (ACPP_InGameGameMode* GameMode = Cast<ACPP_InGameGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		// KillPlayerを呼び出してPlayerを破棄する
		int32 TotalNumber = GameMode->AddCoin(Number);

		UE_LOG(LogTemp, Display, TEXT("TotalNumber:%d"), TotalNumber);
	}
}