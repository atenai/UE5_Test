// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_InGameHUD.h"

void UPauseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//ButtonResumeのOnClickedに「OnButtonResumeClicked」を関連づける
	ButtonResume->OnClicked.AddUniqueDynamic(this, &UPauseWidget::OnButtonResumeClicked);

	//ButtonTitleのOnClickedに「OnButtonTitleClicked」を関連づける
	ButtonTitle->OnClicked.AddUniqueDynamic(this, &UPauseWidget::OnButtonTitleClicked);

	//ButtonQuitのOnClickedに「OnButtonQuitClicked」を関連づける
	ButtonQuit->OnClicked.AddUniqueDynamic(this, &UPauseWidget::OnButtonQuitClicked);
}

void UPauseWidget::OnButtonResumeClicked()
{
	//PlayerControllerを取得する
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUDクラスを取得する
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//Pauseを解除する
	HUD->DispPause(false);
}

void UPauseWidget::OnButtonTitleClicked()
{
	//PlayerControllerを取得する
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUDクラスを取得
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//MainMenuに遷移する
	HUD->OpenLevel(FName(TEXT("MainMenu")));
}

void UPauseWidget::OnButtonQuitClicked()
{
	//PlayerControllerを取得する
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	//CPP_InGameHUDクラスを取得
	ACPP_InGameHUD* HUD = Cast<ACPP_InGameHUD>(PlayerController->GetHUD());

	//ゲームを終了する
	HUD->QuitGame();
}