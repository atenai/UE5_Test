// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

void ACPP_InGameHUD::BeginPlay()
{
	//WidgetBlueprintのClassを取得する
	FString StatusWidgetPath = TEXT("/Game/RollingBall/Blueprint/UI/CPPBPW_Status.CPPBPW_Status_C");
	TSubclassOf<UUserWidget> StatusWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*StatusWidgetPath)).LoadSynchronous();

	//PlayerControllerを取得する
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);

	//WidgetClassとPlayerControllerが取得できたか判定する
	if (StatusWidgetClass && PlayerController)
	{
		//Status表示用のWidgetを作成する
		UUserWidget* StatusWidget = UWidgetBlueprintLibrary::Create(GetWorld(), StatusWidgetClass, PlayerController);

		//Viewportに追加する
		StatusWidget->AddToViewport(0);
	}
}

void ACPP_InGameHUD::DispPause(const bool IsPause)
{
	//PlayerControllerを取得する
	APlayerController* PlayerController = GetOwningPlayerController();

	if (IsPause)
	{
		//Paiseメニューを表示する

		//Paiseメニューを表示する
		PauseWidget->SetVisibility(ESlateVisibility::Visible);

		//UIモードに設定する
		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, PauseWidget, EMouseLockMode::DoNotLock, false);

		//GameをPause状態にする
		UGameplayStatics::SetGamePaused(GetWorld(), true);

		//Mouseカーソルを表示する
		PlayerController->SetShowMouseCursor(true);
	}
	else
	{
		//Pause状態を解除する

		//GameのPause状態を解除する
		UGameplayStatics::SetGamePaused(GetWorld(), false);

		//Mouseカーソルを非表示にする
		PlayerController->SetShowMouseCursor(false);

		//GameのInput状態に戻す
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController, false);

		//Pauseメニューを折りたたみ状態にする
		PauseWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void ACPP_InGameHUD::OpenLevel(const FName LevelName)
{
	//LevelをLoadする
	UGameplayStatics::OpenLevel(GetWorld(), LevelName);
}

void ACPP_InGameHUD::QuitGame()
{
	//ゲームを終了する
	UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayerController(), EQuitPreference::Quit, false);
}