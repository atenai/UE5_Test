// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_InGameHUD.h"

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//ButtonContinueのOnClickedに「OnButtonContinueClicked」を関連づける
	ButtonContinue->OnClicked.AddUniqueDynamic(this, &UGameOverWidget::OnButtonContinueClicked);

	//ButtonTitleのOnClickedに「OnButtonTitleClicked」を関連づける
	ButtonTitle->OnClicked.AddUniqueDynamic(this, &UGameOverWidget::OnButtonTitleClicked);

	//ButtonQuitのOnClickedに「OnButtonQuitClicked」を関連づける
	ButtonQuit->OnClicked.AddUniqueDynamic(this, &UGameOverWidget::OnButtonQuitClicked);
}

void UGameOverWidget::OnButtonContinueClicked()
{
	//PlayerControllerを取得する
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUDを取得する
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//ゲームを再開する
	HUD->ContinueGame();
}

void UGameOverWidget::OnButtonTitleClicked()
{
	//PlayerControllerを取得する
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUDを取得する
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//レベルを開く
	HUD->OpenLevel(FName(TEXT("CPP_MainMenu")));
}

void UGameOverWidget::OnButtonQuitClicked()
{
	//PlayerControllerを取得する
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUDを取得する
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//ゲームを終了する
	HUD->QuitGame();
}