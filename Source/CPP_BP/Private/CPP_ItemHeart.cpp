// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ItemHeart.h"
#include "CPP_BallPlayer.h"//�A�N�Z�X�������N���X�̃w�b�_�[���C���N���[�h
#include "Kismet/GameplayStatics.h"//���̃A�N�^�[��T���ׂɕK�v�ȃw�b�_�[���C���N���[�h
#include "Engine.h"

ACPP_ItemHeart::ACPP_ItemHeart()
{
	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/RollingBall/Items/Meshes/S_Heart"), NULL, LOAD_None, NULL);

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	ItemMesh->SetStaticMesh(Mesh);
}

void ACPP_ItemHeart::GetItem()
{
	// BallPlayer���擾����
	if (ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(),0)))
	{
		// Player���񕜂���
		float Health = Player->Heal(HealValue);

		UE_LOG(LogTemp, Display, TEXT("Health:%f"), Health);

		FString String = FString::FromInt(Health);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, String);
	}
}