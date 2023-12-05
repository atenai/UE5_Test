// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_MainGamePlayerController.generated.h"


UCLASS()
class CPP_BP_API ACPP_MainGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//コンストラクタ宣言がなかったので追加
	ACPP_MainGamePlayerController();

	virtual void SetupInputComponent() override;

	virtual void AddPitchInput(float Val) override;	
	void Fire();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	class ACPP_GameCameraActor* ChangeGameCamera(const FName& Tag);

	UFUNCTION()
	void OnPauseMenu();//Pキーで呼び出される関数

	UPROPERTY()
	TSubclassOf<class UCPP_PauseMenuWidget> PauseMenuWidgetClass;

	UPROPERTY()
	class UCPP_PauseMenuWidget* PauseMenuWidget;

	UFUNCTION()
	void OnPauseMenuGotoTitleButton();

	UFUNCTION()
	void OnPauseMenuCloseButton();

private:
	UPROPERTY()
	TArray<class ACPP_GameCameraActor*> GameCameras;
};
