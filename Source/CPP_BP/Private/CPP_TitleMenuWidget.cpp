// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TitleMenuWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Styling/SlateColor.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/CanvasPanelSlot.h"

bool UCPP_TitleMenuWidget::Initialize()
{
	bool bRet = Super::Initialize();

	//ボタンUIの作成
	{
		//"EASY"テキストの作成
		UTextBlock* EasyButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		EasyButtonTextBlock->SetText(FText::FromString(TEXT("EASY")));
		EasyButtonTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor::Black));

		//EASYボタンの作成
		SelectEasyButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		SelectEasyButton->AddChild(EasyButtonTextBlock);//EASYボタンの子にテキストを追加する

		//"HARD"テキストの作成
		UTextBlock* HardButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		HardButtonTextBlock->SetText(FText::FromString(TEXT("HARD")));
		HardButtonTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor::Black));

		//HARDボタンの作成
		SelectHardButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		SelectHardButton->AddChild(HardButtonTextBlock);//HARDボタンの子にテキストを追加する
	}

	//VerticalBoxを作成し、ボタンを追加する
	UVerticalBox* VerticalBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());//ConstructWidgetはウィジェットを作成する関数
	{
		//EASYボタンをVerticalBoxに追加
		UVerticalBoxSlot* VerticalBoxSlot = VerticalBox->AddChildToVerticalBox(SelectEasyButton);
		VerticalBoxSlot->SetPadding(FMargin(0.0, 40.0, 0.0, 40.0));
		VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));

		//HARDボタンをVerticalBoxに追加
		VerticalBoxSlot = VerticalBox->AddChildToVerticalBox(SelectHardButton);
		VerticalBoxSlot->SetPadding(FMargin(0.0, 40.0, 0.0, 40.0));
		VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
	}

	//CanvasPanelにVerticalBoxを追加する
	UCanvasPanel* RootCanvasPanel = Cast<UCanvasPanel>(GetRootWidget());//GetRootWidgetはユーザーウィジェットに存在する親のウィジェットを取得する関数（この場合はキャンバスパネル）
	if (RootCanvasPanel != nullptr)
	{
		UCanvasPanelSlot* CanvasPanelSlot = RootCanvasPanel->AddChildToCanvas(VerticalBox);
		CanvasPanelSlot->SetAnchors(FAnchors(0.5, 0.5, 0.5, 0.5));
		CanvasPanelSlot->SetPosition(FVector2D(-7.0,1.45));
		CanvasPanelSlot->SetSize(FVector2D(500.0 ,300.0));
		CanvasPanelSlot->SetAlignment(FVector2D(0.5, 0.5));
		//RootCanvasPanel->AddChild(VerticalBox);
	}

	return bRet;
}