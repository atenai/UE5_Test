// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"

class UButton;

UCLASS()
class CPP_BP_API UPauseWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//�l�C�e�B�u�R���X�g���N�^
	void NativeConstruct() override;
	
private:
	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonResume;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonTitle;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonQuit;

	//ButtonResume��OnClicked�C�x���g�Ɋ֘A�Â���
	UFUNCTION()
	void OnButtonResumeClicked();

	//ButtonTitle��OnClicked�C�x���g�Ɋ֘A�Â���
	UFUNCTION()
	void OnButtonTitleClicked();

	//ButtonQuit��OnClicked�C�x���g�Ɋ֘A�Â���
	UFUNCTION()
	void OnButtonQuitClicked();
};
