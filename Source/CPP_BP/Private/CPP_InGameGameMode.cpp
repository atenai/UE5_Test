// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameGameMode.h"
#include "CPP_BallPlayer.h"//#include "(�v���C���[�ƂȂ�Class�̃w�b�_�[�t�@�C��)"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"

//�R���X�g���N�^
ACPP_InGameGameMode::ACPP_InGameGameMode()
{
	//DefaultPawnClass = (�v���C���[�ƂȂ�Class)::StaticClass();
	DefaultPawnClass = ACPP_BallPlayer::StaticClass();
}

void ACPP_InGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Viewport�ɔz�u���ꂽPlayerStart��T��
	const APlayerStart* PlayerStart = Cast<APlayerStart>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass()));

	// PlayerStart�̈ʒu����Resporn�̈ʒu�Ƃ��ĕێ�����
	SpawnTransform = PlayerStart->GetActorTransform();
}

void ACPP_InGameGameMode::RespawnPlayer()
{
	// BallPlayer��Spawn����
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Instigator = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	ACPP_BallPlayer* Player = GetWorld()->SpawnActor<ACPP_BallPlayer>(ACPP_BallPlayer::StaticClass(), SpawnTransform, SpawnInfo);

	// Controller��ݒ肷��
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerController->Possess(Player);
}

void ACPP_InGameGameMode::KillPlayer(ACPP_BallPlayer* Player)
{
	// Player��j������
	Player->Destroy();

	// Respawn���s��
	RespawnPlayer();
}