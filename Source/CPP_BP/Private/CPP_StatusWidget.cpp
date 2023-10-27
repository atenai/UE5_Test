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

	//TextBlockのTextDelegateが有効になっていると参照エラーになってWidgetBlueprintが作成できないので
	//TextDelegateを使っているスクリプトを親クラスにしたWidgetBlueprintを作成する際は、TextDelegateを使っている所はコメントアウトする必要がある
	TextBlockHealth->TextDelegate.BindUFunction(this, "SetTextBlockHealth");
	TextBlockHealthMax->TextDelegate.BindUFunction(this, "SetTextBlockHealthMax");
	TextBlockTotalLifes->TextDelegate.BindUFunction(this, "SetTextBlockTotalLifes");
	TextBlockTotalCoins->TextDelegate.BindUFunction(this, "SetTextBlockTotalCoins");

	return true;
}

FText UCPP_StatusWidget::SetTextBlockHealth()
{
	//CPP_BallPlayerを取得する
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		//PlayerのHealthをTextに設定する
		return FText::FromString(FString::FromInt((int)Player->GetHealth()));
	}

	return FText();
}

FText UCPP_StatusWidget::SetTextBlockHealthMax()
{
	//CPP_BallPlayerを取得する
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		//PlayerのHealthMaxをTextに設定する
		return FText::FromString(FString::FromInt((int)Player->GetHealthMax()));
	}

	return FText();
}

FText UCPP_StatusWidget::SetTextBlockTotalLifes()
{
	//CPP_GameInstanceを取得する
	if (const UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		//GameInstanceのTotalLifesをTextに設定する
		return FText::FromString(FString::FromInt(GameInstance->TotalLifes));
	}

	return FText();
}

FText UCPP_StatusWidget::SetTextBlockTotalCoins()
{
	//CPP_GameInstanceを取得する
	if (const UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		//GameInstanceのTotalCoinsをTextに設定する
		return FText::FromString(FString::FromInt(GameInstance->TotalCoints));
	}

	return FText();
}