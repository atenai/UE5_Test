// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CPP_RollingBallGameInstance.h"

void ACPP_InGameHUD::BeginPlay()
{
	//WidgetBlueprintのClassを取得する
	FString StatusWidgetPath = TEXT("/Game/RollingBall/Blueprint/UI/CPPBPW_Status.CPPBPW_Status_C");
	TSubclassOf<UUserWidget> StatusWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*StatusWidgetPath)).LoadSynchronous();

	//WidgetBlueprintのClassを取得する
	FString PauseWidgetPath = TEXT("/Game/RollingBall/Blueprint/UI/CPPBPW_Pause.CPPBPW_Pause_C");
	TSubclassOf<UUserWidget> PauseWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*PauseWidgetPath)).LoadSynchronous();

	//WidgetBlueprintのClassを取得する
	FString GameOverWidgetPath = TEXT("/Game/RollingBall/Blueprint/UI/CPPBPW_GameOver.CPPBPW_GameOver_C");
	TSubclassOf<UUserWidget> GameOverWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*GameOverWidgetPath)).LoadSynchronous();

	//PlayerControllerを取得する
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);

	//WidgetClassとPlayerControllerが取得できたか判定する
	if (StatusWidgetClass && PauseWidgetClass && GameOverWidgetClass && PlayerController)
	{
		//Status表示用のWidgetを作成する
		UUserWidget* StatusWidget = UWidgetBlueprintLibrary::Create(GetWorld(), StatusWidgetClass, PlayerController);

		//Viewportに追加する
		StatusWidget->AddToViewport(0);

		//Status表示用のWidgetを作成する
		PauseWidget = UWidgetBlueprintLibrary::Create(GetWorld(), PauseWidgetClass, PlayerController);

		//Pauseメニューを折りたたみ状態にする
		PauseWidget->SetVisibility(ESlateVisibility::Collapsed);

		//Viewportに追加する
		PauseWidget->AddToViewport(1);

		//ゲームオーバー用のWidgetを作成する
		GameOverWidget = UWidgetBlueprintLibrary::Create(GetWorld(), GameOverWidgetClass, PlayerController);

		//ゲームオーバーメニューを折りたたみ状態にする
		GameOverWidget->SetVisibility(ESlateVisibility::Collapsed);

		//ビューポートに追加する
		GameOverWidget->AddToViewport(2);
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

void ACPP_InGameHUD::DispGameOver()
{
	//ゲームオーバーウィジェットを表示する
	GameOverWidget->SetVisibility(ESlateVisibility::Visible);

	//プレイヤーコントローラーを取得する
	APlayerController* PlayerController = GetOwningPlayerController();

	//UIモードに設定する
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, GameOverWidget, EMouseLockMode::DoNotLock, false);

	//ゲームをポーズ状態にする
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	//マウスカーソルを表示する
	PlayerController->SetShowMouseCursor(true);
}

void ACPP_InGameHUD::ContinueGame()
{
	//ゲームインスタンスを取得する
	UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	//ゲームインスタンスの変数を初期化する
	GameInstance->Initialize();

	//現在のレベル名を取得する
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());

	//現在のレベルを開きなおす
	UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName));
}