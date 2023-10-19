// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_BallPlayer.h"
#include "CPP_InGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API ACPP_InGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	//コンストラクタ
	ACPP_InGameGameMode();
	
	// PlayerをRespawnする位置情報
	FTransform SpawnTransform;

	//Playerを破棄する
	void KillPlayer(ACPP_BallPlayer* Player);

	//GameをRestartする
	void RestartGame();

	//取得したコインの数
	int32 TotalCoins = 0;

	//取得したコインの枚数を追加する
	int AddCoin(const int32 CoinNumber);

private:
	//PlayerをRespawnする
	void RespawnPlayer();

	//PlayerのLife
	int32 TotalLifes = 3;
};
