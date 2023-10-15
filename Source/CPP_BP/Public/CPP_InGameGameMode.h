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
	//�R���X�g���N�^
	ACPP_InGameGameMode();
	
	// Player��Respawn����ʒu���
	FTransform SpawnTransform;

	//Player��j������
	void KillPlayer(ACPP_BallPlayer* Player);

private:
	//Player��Respawn����
	void RespawnPlayer();
};
