// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

void ACPP_InGameHUD::BeginPlay()
{
	//WidgetBlueprint��Class���擾����
	FString StatusWidgetPath = TEXT("/Game/RollingBall/Blueprint/UI/CPPBPW_Status.CPPBPW_Status_C");
	TSubclassOf<UUserWidget> StatusWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*StatusWidgetPath)).LoadSynchronous();

	//PlayerController���擾����
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);

	//WidgetClass��PlayerController���擾�ł��������肷��
	if (StatusWidgetClass && PlayerController)
	{
		//Status�\���p��Widget���쐬����
		UUserWidget* StatusWidget = UWidgetBlueprintLibrary::Create(GetWorld(), StatusWidgetClass, PlayerController);

		//Viewport�ɒǉ�����
		StatusWidget->AddToViewport(0);
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