// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainMenuGameMode.h"
#include "CPP_MainMenuHUD.h"

ACPP_MainMenuGameMode::ACPP_MainMenuGameMode()
{
	//HUD��ACPP_MainMenuHUD��ݒ肷��
	//ACPP_MainMenuGameMode �� ACPP_MainMenuHUD �� CPPBPW_MainMenu(�X�N���v�g�ł͖���UI�E�B�W�F�b�g) �� UMainMenuWidget
	HUDClass = ACPP_MainMenuHUD::StaticClass();
}
