// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameGameMode.h"
#include "CPP_BallPlayer.h"//#include "(�v���C���[�ƂȂ�Class�̃w�b�_�[�t�@�C��)"
#include "Kismet/GameplayStatics.h"//���̃A�N�^�[��T���ׂɕK�v�ȃw�b�_�[���C���N���[�h
#include "GameFramework/PlayerStart.h"
#include "CPP_RollingBallGameInstance.h"//�A�N�Z�X�������N���X�̃w�b�_�[���C���N���[�h
#include "Engine.h"
#include "CPP_InGameHUD.h"

//�R���X�g���N�^
ACPP_InGameGameMode::ACPP_InGameGameMode()
{
	//DefaultPawnClass = (�v���C���[�ƂȂ�Class)::StaticClass();
	DefaultPawnClass = ACPP_BallPlayer::StaticClass();
	//HUD�ɐݒ肷��
	//ACPP_InGameGameMode �� ACPP_InGameHUD �� CPPBPW_Status(�X�N���v�g�ł͖���UI�E�B�W�F�b�g) �� UCPP_StatusWidget
	HUDClass = ACPP_InGameHUD::StaticClass();
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

	// TotalLifes��Decriment����
	//TotalLifes--;

	//if (0 <= TotalLifes)
	//{
	//	// Respawn���s��
	//	RespawnPlayer();
	//}
	//else
	//{
	//	// Game��Restart����
	//	UE_LOG(LogTemp, Display, TEXT("GameOver"));
	//	RestartGame();
	//}

	// GameInstance���擾����
	UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// TotalLifes��Decriment����
	GameInstance->TotalLifes--;

	if (0 <= GameInstance->TotalLifes)
	{
		// Respawn���s��
		RespawnPlayer();
	}
	else
	{
		// Game��Restart����
		UE_LOG(LogTemp, Display, TEXT("GameOver"));
		RestartGame();
	}
}

void ACPP_InGameGameMode::RestartGame()
{
	// GameInstance���擾����
	UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// GameInstance�̕ϐ�������������
	GameInstance->Initialize();

	FString String = FString::FromInt(GameInstance->TotalCoints);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, String);

	// ���݂�LevelName���擾����
	//const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());

	// ���݂�Level���J���Ȃ���
	UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName));
}

int ACPP_InGameGameMode::AddCoin(const int32 CoinNumber)
{
	// �擾�����R�C���̖�����ǉ�����
	//TotalCoins = TotalCoins + CoinNumber;

	//return TotalCoins;

	// GameInstance���擾����
	UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// �擾�����R�C���̖�����ǉ�����
	GameInstance->TotalCoints = GameInstance->TotalCoints + CoinNumber;

	FString String = FString::FromInt(GameInstance->TotalCoints);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, String);

	return GameInstance->TotalCoints;
}