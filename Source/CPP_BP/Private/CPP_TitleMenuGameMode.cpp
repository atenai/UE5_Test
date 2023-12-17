// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TitleMenuGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_MyGameInstance.h"

ACPP_TitleMenuGameMode::ACPP_TitleMenuGameMode() : Super()
{
	static ConstructorHelpers::FClassFinder<APlayerController> PCClass(TEXT("/Game/Blueprints/BP_TitleMenuPlayerController"));
	if (PCClass.Succeeded())
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, TEXT("Title1"));
		PlayerControllerClass = PCClass.Class;
	}
}

void ACPP_TitleMenuGameMode::StartGame(EMyGameDifficultType Type)
{
	UCPP_MyGameInstance* GameInstance = Cast<UCPP_MyGameInstance>(GetGameInstance());
	if (GameInstance != nullptr)
	{
		GameInstance->DifficultType = Type;//ìÔà’ìxÇï€éùÇ∑ÇÈ
		UGameplayStatics::OpenLevel(this, TEXT("/Game/Maps/MainGame"));
	}
}
