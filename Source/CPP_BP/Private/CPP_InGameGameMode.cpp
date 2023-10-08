// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameGameMode.h"
#include "CPP_BallPlayer.h"//#include "(プレイヤーとなるClassのヘッダーファイル)"

//コンストラクタ
ACPP_InGameGameMode::ACPP_InGameGameMode()
{
	//DefaultPawnClass = (プレイヤーとなるClass)::StaticClass();
	DefaultPawnClass = ACPP_BallPlayer::StaticClass();
}