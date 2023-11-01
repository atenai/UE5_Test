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
	//Pause���j���[�̕\��/��\��
	void DispPause(const bool IsPause);

	//Level���J��
	void OpenLevel(const FName LevelName);

	//Game���I������
	void QuitGame();

	//�Q�[���I�[�o�[���j���[��\������
	void DispGameOver();

	//�Q�[�����ĊJ����
	void ContinueGame();

private:
	//PauseWidget��ێ�����ϐ�
	UUserWidget* PauseWidget;

	//GameOverWidget��ێ�����ϐ�
	UUserWidget* GameOverWidget;
};
