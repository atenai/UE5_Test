// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainMenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void ACPP_MainMenuHUD::BeginPlay()
{
	// WidgetBlueprint��Class���擾����
	FString Path = TEXT("/Game/RollingBall/UI/MainMenu/CPPBPW_MainMenu.CPPBPW_MainMenu_C");
	TSubclassOf<UUserWidget> WidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*Path)).LoadSynchronous();

	// PlayerController���擾����
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);

	// WidgetClass��PlayerController���擾�ł��������肷��
	if (WidgetClass && PlayerController)
	{
		// Widget���쐬����
		UUserWidget* UserWidget = UWidgetBlueprintLibrary::Create(GetWorld(), WidgetClass, PlayerController);

		// Viewport�ɒǉ�����
		UserWidget->AddToViewport(0);

		// MouseCursor��\������
		UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController, UserWidget, EMouseLockMode::DoNotLock, true, false);
		PlayerController->SetShowMouseCursor(true);
	}
}
