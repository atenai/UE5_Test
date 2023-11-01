// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CPP_InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API ACPP_InGameHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	//Pauseメニューの表示/非表示
	void DispPause(const bool IsPause);

	//Levelを開く
	void OpenLevel(const FName LevelName);

	//Gameを終了する
	void QuitGame();

	//ゲームオーバーメニューを表示する
	void DispGameOver();

	//ゲームを再開する
	void ContinueGame();

private:
	//PauseWidgetを保持する変数
	UUserWidget* PauseWidget;

	//GameOverWidgetを保持する変数
	UUserWidget* GameOverWidget;
};
