// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainMenuGameMode.h"
#include "CPP_MainMenuHUD.h"

ACPP_MainMenuGameMode::ACPP_MainMenuGameMode()
{
	//HUDにACPP_MainMenuHUDを設定する
	//ACPP_MainMenuGameMode → ACPP_MainMenuHUD → CPPBPW_MainMenu(スクリプトでは無くUIウィジェット) → UMainMenuWidget
	HUDClass = ACPP_MainMenuHUD::StaticClass();
}
