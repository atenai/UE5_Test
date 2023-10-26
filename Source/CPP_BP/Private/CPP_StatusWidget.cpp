// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_StatusWidget.h"
#include "Components/TextBlock.h"
#include "CPP_BallPlayer.h"
#include "CPP_RollingBallGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UCPP_StatusWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

bool UCPP_StatusWidget::Initialize()
{
	bool Success = Super::Initialize();

	if (!Success)
	{
		return false;
	}

	TextBlockHealth->TextDelegate.BindUFunction(this, "SetTextBlockHealth");
	TextBlockHealthMax->TextDelegate.BindUFunction(this, "SetTextBlockHealthMax");
	TextBlockTotalLifes->TextDelegate.BindUFunction(this, "SetTextBlockTotalLifes");
	TextBlockTotalCoins->TextDelegate.BindUFunction(this, "SetTextBlockTotalCoins");

	return true;
}

FText UCPP_StatusWidget::SetTextBlockHealth()
{
	//CPP_BallPlayer‚ðŽæ“¾‚·‚é
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		//Player‚ÌHealth‚ðText‚ÉÝ’è‚·‚é
		return FText::FromString(FString::FromInt((int)Player->GetHealth()));
	}

	return FText();
}

FText UCPP_StatusWidget::SetTextBlockHealthMax()
{
	//CPP_BallPlayer‚ðŽæ“¾‚·‚é
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		//Player‚ÌHealthMax‚ðText‚ÉÝ’è‚·‚é
		return FText::FromString(FString::FromInt((int)Player->GetHealthMax()));
	}

	return FText();
}

FText UCPP_StatusWidget::SetTextBlockTotalLifes()
{
	//CPP_GameInstance‚ðŽæ“¾‚·‚é
	if (const UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		//GameInstance‚ÌTotalLifes‚ðText‚ÉÝ’è‚·‚é
		return FText::FromString(FString::FromInt(GameInstance->TotalLifes));
	}

	return FText();
}

FText UCPP_StatusWidget::SetTextBlockTotalCoins()
{
	//CPP_GameInstance‚ðŽæ“¾‚·‚é
	if (const UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		//GameInstance‚ÌTotalCoins‚ðText‚ÉÝ’è‚·‚é
		return FText::FromString(FString::FromInt(GameInstance->TotalCoints));
	}

	return FText();
}