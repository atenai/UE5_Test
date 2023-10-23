// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "CPP_RollingBallGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// ButtonPlay��OnClicked�ɁuOnButtonPlayClicked�v���֘A�Â���
	ButtonPlay->OnClicked.AddUniqueDynamic(this, &UMainMenuWidget::OnButtonPlayClicked);

	// ButtonQuit��OnClicked�ɁuOnButtonQuitClicked�v���֘A�Â���
	ButtonQuit->OnClicked.AddUniqueDynamic(this, &UMainMenuWidget::OnButtonQuitClicked);
}

void UMainMenuWidget::OnButtonPlayClicked()
{
	// GameInstance�̕ϐ�������������
	UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GameInstance->Initialize();

	// Level01��Load����
	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("Level01")));
}

void UMainMenuWidget::OnButtonQuitClicked()
{
	// PlayerController���擾����
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		// �Q�[�����I������
		UKismetSystemLibrary::QuitGame(GetWorld(), PlayerController, EQuitPreference::Quit, false);
	}

}