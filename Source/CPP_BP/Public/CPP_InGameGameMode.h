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

private:
	//PlayerをRespawnする
	void RespawnPlayer();
};
