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

	//�{�^��UI�̍쐬
	{
		//"EASY"�e�L�X�g�̍쐬
		UTextBlock* EasyButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		EasyButtonTextBlock->SetText(FText::FromString(TEXT("EASY")));
		EasyButtonTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor::Black));

		//EASY�{�^���̍쐬
		SelectEasyButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		SelectEasyButton->AddChild(EasyButtonTextBlock);//EASY�{�^���̎q�Ƀe�L�X�g��ǉ�����

		//"HARD"�e�L�X�g�̍쐬
		UTextBlock* HardButtonTextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		HardButtonTextBlock->SetText(FText::FromString(TEXT("HARD")));
		HardButtonTextBlock->SetColorAndOpacity(FSlateColor(FLinearColor::Black));

		//HARD�{�^���̍쐬
		SelectHardButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		SelectHardButton->AddChild(HardButtonTextBlock);//HARD�{�^���̎q�Ƀe�L�X�g��ǉ�����
	}

	//VerticalBox���쐬���A�{�^����ǉ�����
	UVerticalBox* VerticalBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());//ConstructWidget�̓E�B�W�F�b�g���쐬����֐�
	{
		//EASY�{�^����VerticalBox�ɒǉ�
		UVerticalBoxSlot* VerticalBoxSlot = VerticalBox->AddChildToVerticalBox(SelectEasyButton);
		VerticalBoxSlot->SetPadding(FMargin(0.0, 40.0, 0.0, 40.0));
		VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));

		//HARD�{�^����VerticalBox�ɒǉ�
		VerticalBoxSlot = VerticalBox->AddChildToVerticalBox(SelectHardButton);
		VerticalBoxSlot->SetPadding(FMargin(0.0, 40.0, 0.0, 40.0));
		VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
	}

	//CanvasPanel��VerticalBox��ǉ�����
	UCanvasPanel* RootCanvasPanel = Cast<UCanvasPanel>(GetRootWidget());//GetRootWidget�̓��[�U�[�E�B�W�F�b�g�ɑ��݂���e�̃E�B�W�F�b�g���擾����֐��i���̏ꍇ�̓L�����o�X�p�l���j
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