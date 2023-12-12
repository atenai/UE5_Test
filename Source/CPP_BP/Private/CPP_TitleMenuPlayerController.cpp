// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TitleMenuPlayerController.h"
#include "CPP_TitleMenuPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "CPP_TitleMenuWidget.h"
#include "Components/Button.h"

ACPP_TitleMenuPlayerController::ACPP_TitleMenuPlayerController() : Super()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Game/WBP_TitleMenu"));
	if (WidgetClass.Succeeded())
	{
		TitleMenuWidgetClass = WidgetClass.Class;
	}
}

void ACPP_TitleMenuPlayerController::BeginPlay()
{
	if (TitleMenuWidget != nullptr)
	{
		TitleMenuWidget = CreateWidget<UCPP_TitleMenuWidget>(this, TitleMenuWidgetClass.Get());
		if (TitleMenuWidget)
		{
			TitleMenuWidget->AddToViewport(0);

			TitleMenuWidget->SelectEasyButton->OnClicked.AddDynamic(this, &ACPP_TitleMenuPlayerController::OnPushedEasyButton);
			TitleMenuWidget->SelectHardButton->OnClicked.AddDynamic(this, &ACPP_TitleMenuPlayerController::OnPushedHardButton);
		}
	}

	bShowMouseCursor = true;//マウスを表示させておく
	Super::BeginPlay();
}

void ACPP_TitleMenuPlayerController::OnPushedEasyButton()
{

}

void ACPP_TitleMenuPlayerController::OnPushedHardButton()
{

}