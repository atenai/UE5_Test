// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_InGameHUD.h"

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//ButtonContinue��OnClicked�ɁuOnButtonContinueClicked�v���֘A�Â���
	ButtonContinue->OnClicked.AddUniqueDynamic(this, &UGameOverWidget::OnButtonContinueClicked);

	//ButtonTitle��OnClicked�ɁuOnButtonTitleClicked�v���֘A�Â���
	ButtonTitle->OnClicked.AddUniqueDynamic(this, &UGameOverWidget::OnButtonTitleClicked);

	//ButtonQuit��OnClicked�ɁuOnButtonQuitClicked�v���֘A�Â���
	ButtonQuit->OnClicked.AddUniqueDynamic(this, &UGameOverWidget::OnButtonQuitClicked);
}

void UGameOverWidget::OnButtonContinueClicked()
{
	//PlayerController���擾����
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUD���擾����
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//�Q�[�����ĊJ����
	HUD->ContinueGame();
}

void UGameOverWidget::OnButtonTitleClicked()
{
	//PlayerController���擾����
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUD���擾����
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//���x�����J��
	HUD->OpenLevel(FName(TEXT("CPP_MainMenu")));
}

void UGameOverWidget::OnButtonQuitClicked()
{
	//PlayerController���擾����
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUD���擾����
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//�Q�[�����I������
	HUD->QuitGame();
}