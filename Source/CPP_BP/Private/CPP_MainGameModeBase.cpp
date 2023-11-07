// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainGameModeBase.h"
#include "UObject/ConstructorHelpers.h"

ACPP_MainGameModeBase::ACPP_MainGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//ブループリントのキャラクターを取得
	static ConstructorHelpers::FClassFinder<APawn> PawnClass(TEXT("/Game/Blueprints/BP_PlayerPawn"));

	//取得に成功したら中身を実行する
	if (PawnClass.Succeeded())
	{
		//キャラクターをゲームモードのデフォルトポーンクラスに設定
		DefaultPawnClass = PawnClass.Class;
	}
}