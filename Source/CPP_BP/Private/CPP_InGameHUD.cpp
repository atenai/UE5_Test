// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void ACPP_InGameHUD::BeginPlay()
{
	//WidgetBlueprint‚ÌClass‚ðŽæ“¾‚·‚é
	FString StatusWidgetPath = TEXT("/Game/RollingBall/Blueprint/UI/CPPBPW_Status.CPPBPW_Status_C");
	TSubclassOf<UUserWidget> StatusWidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*StatusWidgetPath)).LoadSynchronous();

	//PlayerController‚ðŽæ“¾‚·‚é
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);

	//WidgetClass‚ÆPlayerController‚ªŽæ“¾‚Å‚«‚½‚©”»’è‚·‚é
	if (StatusWidgetClass && PlayerController)
	{
		//Status•\Ž¦—p‚ÌWidget‚ðì¬‚·‚é
		UUserWidget* StatusWidget = UWidgetBlueprintLibrary::Create(GetWorld(), StatusWidgetClass, PlayerController);

		//Viewport‚É’Ç‰Á‚·‚é
		StatusWidget->AddToViewport(0);
	}
}
