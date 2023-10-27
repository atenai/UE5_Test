// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameGameMode.h"
#include "CPP_BallPlayer.h"//#include "(プレイヤーとなるClassのヘッダーファイル)"
#include "Kismet/GameplayStatics.h"//他のアクターを探す為に必要なヘッダーをインクルード
#include "GameFramework/PlayerStart.h"
#include "CPP_RollingBallGameInstance.h"//アクセスしたいクラスのヘッダーをインクルード
#include "Engine.h"
#include "CPP_InGameHUD.h"

//コンストラクタ
ACPP_InGameGameMode::ACPP_InGameGameMode()
{
	//DefaultPawnClass = (プレイヤーとなるClass)::StaticClass();
	DefaultPawnClass = ACPP_BallPlayer::StaticClass();
	//HUDに設定する
	//ACPP_InGameGameMode → ACPP_InGameHUD → CPPBPW_Status(スクリプトでは無くUIウィジェット) → UCPP_StatusWidget
	HUDClass = ACPP_InGameHUD::StaticClass();
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
	//TotalLifes--;

	//if (0 <= TotalLifes)
	//{
	//	// Respawnを行う
	//	RespawnPlayer();
	//}
	//else
	//{
	//	// GameをRestartする
	//	UE_LOG(LogTemp, Display, TEXT("GameOver"));
	//	RestartGame();
	//}

	// GameInstanceを取得する
	UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// TotalLifesをDecrimentする
	GameInstance->TotalLifes--;

	if (0 <= GameInstance->TotalLifes)
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
	// GameInstanceを取得する
	UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// GameInstanceの変数を初期化する
	GameInstance->Initialize();

	FString String = FString::FromInt(GameInstance->TotalCoints);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, String);

	// 現在のLevelNameを取得する
	//const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());

	// 現在のLevelを開きなおす
	UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName));
}

int ACPP_InGameGameMode::AddCoin(const int32 CoinNumber)
{
	// 取得したコインの枚数を追加する
	//TotalCoins = TotalCoins + CoinNumber;

	//return TotalCoins;

	// GameInstanceを取得する
	UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// 取得したコインの枚数を追加する
	GameInstance->TotalCoints = GameInstance->TotalCoints + CoinNumber;

	FString String = FString::FromInt(GameInstance->TotalCoints);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, String);

	return GameInstance->TotalCoints;
}