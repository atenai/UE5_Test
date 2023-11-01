// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

class UButton;

UCLASS()
class CPP_BP_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//�l�C�e�B�u�R���X�g���N�^
	void NativeConstruct() override;
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ButtonContinue;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ButtonTitle;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ButtonQuit;

	//ButtonContinue��OnClicked�C�x���g�Ɋ֘A�Â���
	UFUNCTION()
	void OnButtonContinueClicked();

	//ButtonTitle��OnClicked�C�x���g�Ɋ֘A�Â���
	UFUNCTION()
	void OnButtonTitleClicked();

	//ButtonQuit��OnClicked�C�x���g�Ɋ֘A�Â���
	UFUNCTION()
	void OnButtonQuitClicked();
};
