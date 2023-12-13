// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TitleMenuGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "Engine.h"

ACPP_TitleMenuGameMode::ACPP_TitleMenuGameMode() : Super()
{
	static ConstructorHelpers::FClassFinder<APlayerController> PCClass(TEXT("/Game/Blueprints/BP_TitleMenuPlayerController"));
	if (PCClass.Succeeded())
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, TEXT("Title1"));
		PlayerControllerClass = PCClass.Class;
	}
}
