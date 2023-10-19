// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ItemCoin.h"
#include "CPP_InGameGameMode.h"
#include "Kismet/GameplayStatics.h"

ACPP_ItemCoin::ACPP_ItemCoin()
{
	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Items/Meshes/S_Coin"));

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	ItemMesh->SetStaticMesh(Mesh);
}

void ACPP_ItemCoin::GetItem()
{
	// GameMode���擾���āAInGameGameMode��Cast����
	if (ACPP_InGameGameMode* GameMode = Cast<ACPP_InGameGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		// KillPlayer���Ăяo����Player��j������
		int32 TotalNumber = GameMode->AddCoin(Number);

		UE_LOG(LogTemp, Display, TEXT("TotalNumber:%d"), TotalNumber);
	}
}