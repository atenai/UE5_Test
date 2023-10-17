// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameGameMode.h"
#include "CPP_BallPlayer.h"//#include "(プレイヤーとなるClassのヘッダーファイル)"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"

//コンストラクタ
ACPP_InGameGameMode::ACPP_InGameGameMode()
{
	//DefaultPawnClass = (プレイヤーとなるClass)::StaticClass();
	DefaultPawnClass = ACPP_BallPlayer::StaticClass();
}

void ACPP_InGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Viewportに配置されたPlayerStartを探す
	const APlayerStart* PlayerStart = Cast<APlayerStart>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass()));

	// PlayerStartの位置情報をRespornの位置として保持する
	SpawnTransform = PlayerStart->GetActorTransform();
}

void ACPP_InGameGameMode::RespawnPlayer()
{
	// BallPlayerをSpawnする
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Instigator = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	ACPP_BallPlayer* Player = GetWorld()->SpawnActor<ACPP_BallPlayer>(ACPP_BallPlayer::StaticClass(), SpawnTransform, SpawnInfo);

	// Controllerを設定する
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerController->Possess(Player);
}

void ACPP_InGameGameMode::KillPlayer(ACPP_BallPlayer* Player)
{
	// Playerを破棄する
	Player->Destroy();

	// TotalLifesをDecrimentする
	TotalLifes--;

	if (0 <= TotalLifes)
	{
		// Respawnを行う
		RespawnPlayer();
	}
	else
	{
		// GameをRestartする
		UE_LOG(LogTemp, Display, TEXT("GameOver"));
		RestartGame();
	}
}

void ACPP_InGameGameMode::RestartGame()
{
	// 現在のLevelNameを取得する
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());

	// 現在のLevelを開きなおす
	UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName));
}