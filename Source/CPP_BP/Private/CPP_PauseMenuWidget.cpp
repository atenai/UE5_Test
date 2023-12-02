// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PauseMenuWidget.h"
#include "Components/Button.h"

bool UCPP_PauseMenuWidget::Initialize()
{
	bool bRet = Super::Initialize();
	GoToTitleButton->OnClicked.AddDynamic(this, &UCPP_PauseMenuWidget::OnClickedGoToTitle);
	CloseMenuButton->OnClicked.AddDynamic(this, &UCPP_PauseMenuWidget::OnClickedClose);

	return bRet;
}

void UCPP_PauseMenuWidget::OnClickedGoToTitle()
{

}

void UCPP_PauseMenuWidget::OnClickedClose()
{
	if (IsInViewport())
	{
		RemoveFromParent();
	}
}