// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_RollingBallGameInstance.h"

void ACPP_InGameHUD::BeginPlay()
{
	//WidgetBlueprint��Class���擾����
	FString StatusWidgetPath = TEXT("/Game/RollingBall/Blueprint/UI/CPPBPW_Status.CPPBPW_Status_C");
	TSubclassOf<UUserWidget> StatusWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*StatusWidgetPath)).LoadSynchronous();

	//WidgetBlueprint��Class���擾����
	FString PauseWidgetPath = TEXT("/Game/RollingBall/Blueprint/UI/CPPBPW_Pause.CPPBPW_Pause_C");
	TSubclassOf<UUserWidget> PauseWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*PauseWidgetPath)).LoadSynchronous();

	//WidgetBlueprint��Class���擾����
	FString GameOverWidgetPath = TEXT("/Game/RollingBall/Blueprint/UI/CPPBPW_GameOver.CPPBPW_GameOver_C");
	TSubclassOf<UUserWidget> GameOverWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*GameOverWidgetPath)).LoadSynchronous();

	//PlayerController���擾����
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);

	//WidgetClass��PlayerController���擾�ł��������肷��
	if (StatusWidgetClass && PauseWidgetClass && GameOverWidgetClass && PlayerController)
	{
		//Status�\���p��Widget���쐬����
		UUserWidget* StatusWidget = UWidgetBlueprintLibrary::Create(GetWorld(), StatusWidgetClass, PlayerController);

		//Viewport�ɒǉ�����
		StatusWidget->AddToViewport(0);

		//Status�\���p��Widget���쐬����
		PauseWidget = UWidgetBlueprintLibrary::Create(GetWorld(), PauseWidgetClass, PlayerController);

		//Pause���j���[��܂肽���ݏ�Ԃɂ���
		PauseWidget->SetVisibility(ESlateVisibility::Collapsed);

		//Viewport�ɒǉ�����
		PauseWidget->AddToViewport(1);

		//�Q�[���I�[�o�[�p��Widget���쐬����
		GameOverWidget = UWidgetBlueprintLibrary::Create(GetWorld(), GameOverWidgetClass, PlayerController);

		//�Q�[���I�[�o�[���j���[��܂肽���ݏ�Ԃɂ���
		GameOverWidget->SetVisibility(ESlateVisibility::Collapsed);

		//�r���[�|�[�g�ɒǉ�����
		GameOverWidget->AddToViewport(2);
	}
}

void ACPP_InGameHUD::DispPause(const bool IsPause)
{
	//PlayerController���擾����
	APlayerController* PlayerController = GetOwningPlayerController();

	if (IsPause)
	{
		//Paise���j���[��\������

		//Paise���j���[��\������
		PauseWidget->SetVisibility(ESlateVisibility::Visible);

		//UI���[�h�ɐݒ肷��
		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, PauseWidget, EMouseLockMode::DoNotLock, false);

		//Game��Pause��Ԃɂ���
		UGameplayStatics::SetGamePaused(GetWorld(), true);

		//Mouse�J�[�\����\������
		PlayerController->SetShowMouseCursor(true);
	}
	else
	{
		//Pause��Ԃ���������

		//Game��Pause��Ԃ���������
		UGameplayStatics::SetGamePaused(GetWorld(), false);

		//Mouse�J�[�\�����\���ɂ���
		PlayerController->SetShowMouseCursor(false);

		//Game��Input��Ԃɖ߂�
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController, false);

		//Pause���j���[��܂肽���ݏ�Ԃɂ���
		PauseWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void ACPP_InGameHUD::OpenLevel(const FName LevelName)
{
	//Level��Load����
	UGameplayStatics::OpenLevel(GetWorld(), LevelName);
}

void ACPP_InGameHUD::QuitGame()
{
	//�Q�[�����I������
	UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayerController(), EQuitPreference::Quit, false);
}

void ACPP_InGameHUD::DispGameOver()
{
	//�Q�[���I�[�o�[�E�B�W�F�b�g��\������
	GameOverWidget->SetVisibility(ESlateVisibility::Visible);

	//�v���C���[�R���g���[���[���擾����
	APlayerController* PlayerController = GetOwningPlayerController();

	//UI���[�h�ɐݒ肷��
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, GameOverWidget, EMouseLockMode::DoNotLock, false);

	//�Q�[�����|�[�Y��Ԃɂ���
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	//�}�E�X�J�[�\����\������
	PlayerController->SetShowMouseCursor(true);
}

void ACPP_InGameHUD::ContinueGame()
{
	//�Q�[���C���X�^���X���擾����
	UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	//�Q�[���C���X�^���X�̕ϐ�������������
	GameInstance->Initialize();

	//���݂̃��x�������擾����
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());

	//���݂̃��x�����J���Ȃ���
	UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName));
}