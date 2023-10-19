// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ItemCoin.h"
#include "CPP_InGameGameMode.h"
#include "Kismet/GameplayStatics.h"

ACPP_ItemCoin::ACPP_ItemCoin()
{
	// StaticMesh‚ğLaod‚µ‚ÄStaticMeshComponent‚ÌStaticMesh‚Éİ’è‚·‚é
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Items/Meshes/S_Coin"));

	// StaticMesh‚ğStaticMeshComponent‚Éİ’è‚·‚é
	ItemMesh->SetStaticMesh(Mesh);
}

void ACPP_ItemCoin::GetItem()
{
	// GameMode‚ğæ“¾‚µ‚ÄAInGameGameMode‚ÉCast‚·‚é
	if (ACPP_InGameGameMode* GameMode = Cast<ACPP_InGameGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		// KillPlayer‚ğŒÄ‚Ño‚µ‚ÄPlayer‚ğ”jŠü‚·‚é
		int32 TotalNumber = GameMode->AddCoin(Number);

		UE_LOG(LogTemp, Display, TEXT("TotalNumber:%d"), TotalNumber);
	}
}