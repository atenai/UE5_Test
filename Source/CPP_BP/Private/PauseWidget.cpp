// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_InGameHUD.h"

void UPauseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//ButtonResume��OnClicked�ɁuOnButtonResumeClicked�v���֘A�Â���
	ButtonResume->OnClicked.AddUniqueDynamic(this, &UPauseWidget::OnButtonResumeClicked);

	//ButtonTitle��OnClicked�ɁuOnButtonTitleClicked�v���֘A�Â���
	ButtonTitle->OnClicked.AddUniqueDynamic(this, &UPauseWidget::OnButtonTitleClicked);

	//ButtonQuit��OnClicked�ɁuOnButtonQuitClicked�v���֘A�Â���
	ButtonQuit->OnClicked.AddUniqueDynamic(this, &UPauseWidget::OnButtonQuitClicked);
}

void UPauseWidget::OnButtonResumeClicked()
{
	//PlayerController���擾����
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUD�N���X���擾����
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//Pause����������
	HUD->DispPause(false);
}

void UPauseWidget::OnButtonTitleClicked()
{
	//PlayerController���擾����
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUD�N���X���擾
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//MainMenu�ɑJ�ڂ���
	HUD->OpenLevel(FName(TEXT("MainMenu")));
}

void UPauseWidget::OnButtonQuitClicked()
{
	//PlayerController���擾����
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUD�N���X���擾
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//�Q�[�����I������
	HUD->QuitGame();
}