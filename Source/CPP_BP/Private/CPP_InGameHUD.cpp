// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

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
