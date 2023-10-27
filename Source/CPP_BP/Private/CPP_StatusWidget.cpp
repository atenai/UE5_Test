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

	//TextBlock��TextDelegate���L���ɂȂ��Ă���ƎQ�ƃG���[�ɂȂ���WidgetBlueprint���쐬�ł��Ȃ��̂�
	//TextDelegate���g���Ă���X�N���v�g��e�N���X�ɂ���WidgetBlueprint���쐬����ۂ́ATextDelegate���g���Ă��鏊�̓R�����g�A�E�g����K�v������
	TextBlockHealth->TextDelegate.BindUFunction(this, "SetTextBlockHealth");
	TextBlockHealthMax->TextDelegate.BindUFunction(this, "SetTextBlockHealthMax");
	TextBlockTotalLifes->TextDelegate.BindUFunction(this, "SetTextBlockTotalLifes");
	TextBlockTotalCoins->TextDelegate.BindUFunction(this, "SetTextBlockTotalCoins");

	return true;
}

FText UCPP_StatusWidget::SetTextBlockHealth()
{
	//CPP_BallPlayer���擾����
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		//Player��Health��Text�ɐݒ肷��
		return FText::FromString(FString::FromInt((int)Player->GetHealth()));
	}

	return FText();
}

FText UCPP_StatusWidget::SetTextBlockHealthMax()
{
	//CPP_BallPlayer���擾����
	if (const ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		//Player��HealthMax��Text�ɐݒ肷��
		return FText::FromString(FString::FromInt((int)Player->GetHealthMax()));
	}

	return FText();
}

FText UCPP_StatusWidget::SetTextBlockTotalLifes()
{
	//CPP_GameInstance���擾����
	if (const UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		//GameInstance��TotalLifes��Text�ɐݒ肷��
		return FText::FromString(FString::FromInt(GameInstance->TotalLifes));
	}

	return FText();
}

FText UCPP_StatusWidget::SetTextBlockTotalCoins()
{
	//CPP_GameInstance���擾����
	if (const UCPP_RollingBallGameInstance* GameInstance = Cast<UCPP_RollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		//GameInstance��TotalCoins��Text�ɐݒ肷��
		return FText::FromString(FString::FromInt(GameInstance->TotalCoints));
	}

	return FText();
}