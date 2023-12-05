// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainGamePlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "CPP_PlayerPawn.h"
#include "Engine.h"
#include "CPP_GameCameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "CPP_PauseMenuWidget.h"
#include "Components/Button.h"

ACPP_MainGamePlayerController::ACPP_MainGamePlayerController() : Super()
{
	static ConstructorHelpers::FClassFinder<UCPP_PauseMenuWidget> PauseMenuClass(TEXT("/Game/WBP_PauseMenu"));
	if (PauseMenuClass.Succeeded())
	{
		PauseMenuWidgetClass = PauseMenuClass.Class;
	}
}

void ACPP_MainGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	//MouseY�����͂��ꂽ��o�C���h�����֐����ĂԂ悤�ɓo�^
	GetMutableDefault<UInputSettings>()->AddAxisMapping(FInputAxisKeyMapping("Player_MovePitch", EKeys::MouseY, 1.0f));//�����ŃA�����A���G���W���ɑ�����@��o�^
	InputComponent->BindAxis("Player_MovePitch", this, &ACPP_MainGamePlayerController::AddPitchInput);//�����œo�^����������@�Ɋ֐����o�C���h

	//���}�E�X�{�^���������ꂽ��o�C���h�����֐����ĂԂ悤�ɓo�^
	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Fire", EKeys::LeftMouseButton));//�����ŃA�����A���G���W���ɑ�����@��o�^
	InputComponent->BindAction("Player_Fire", IE_Pressed, this, &ACPP_MainGamePlayerController::Fire);//�����œo�^����������@�Ɋ֐����o�C���h

	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Pause", EKeys::P));
	InputComponent->BindAction("Player_Pause", IE_Pressed, this, &ACPP_MainGamePlayerController::OnPauseMenu);
}

//"Player_MovePitch"���͂ɔ�������֐�
void ACPP_MainGamePlayerController::AddPitchInput(float Val)
{
	Super::AddPitchInput(Val);
	ACPP_PlayerPawn* PossessedPawn = Cast<ACPP_PlayerPawn>(GetPawn());
	if (PossessedPawn != nullptr)
	{
		PossessedPawn->MouseMovePitchInput(Val);
	}
}

void ACPP_MainGamePlayerController::Fire()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Fire1"));
	ACPP_PlayerPawn* PossessedPawn = Cast<ACPP_PlayerPawn>(GetPawn());
	if (PossessedPawn != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Fire2"));
		PossessedPawn->Fire();
	}
}

void ACPP_MainGamePlayerController::BeginPlay()
{
	TArray<AActor*> FindedActors;
	UGameplayStatics::GetAllActorsOfClass(this, ACPP_GameCameraActor::StaticClass(), FindedActors);

	for (AActor* Actor : FindedActors)
	{
		ACPP_GameCameraActor* Camera = Cast<ACPP_GameCameraActor>(Actor);
		if (Camera != nullptr)
		{
			GameCameras.Add(Camera);
		}
	}

	if (PauseMenuWidgetClass != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("Pause1"));
		PauseMenuWidget = CreateWidget<UCPP_PauseMenuWidget>(this, PauseMenuWidgetClass);
		PauseMenuWidget->GoToTitleButton->OnClicked.AddDynamic(this, &ACPP_MainGamePlayerController::OnPauseMenuGotoTitleButton);
		PauseMenuWidget->CloseMenuButton->OnClicked.AddDynamic(this, &ACPP_MainGamePlayerController::OnPauseMenuCloseButton);
	}

	//Super::BeginPlay�͍Ō�ɌĂ�ł����iBlueprint�̏�������ɍs����H���Q�Ɓj
	Super::BeginPlay();
}

ACPP_GameCameraActor* ACPP_MainGamePlayerController::ChangeGameCamera(const FName& Tag)
{
	for (ACPP_GameCameraActor* Camera : GameCameras)//foreach
	{
		if (Camera != nullptr)
		{
			if (Camera->ActorHasTag(Tag))
			{
				//�؂�ւ������J�����𔭌�
				SetViewTargetWithBlend(Cast<AActor>(Camera));
				return Camera;
			}
		}
	}

	return Cast<ACPP_GameCameraActor>(GetViewTarget());
}

void ACPP_MainGamePlayerController::OnPauseMenu()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("Pause2"));
	if (PauseMenuWidget != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("Pause3"));
		if (!PauseMenuWidget->IsInViewport())
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("Pause4"));
			PauseMenuWidget->AddToViewport();

			//UMG�ȊO�̃C���v�b�g���������Ȃ��悤�ɂ���
			SetInputMode(FInputModeUIOnly().SetLockMouseToViewportBehavior(EMouseLockMode::LockOnCapture).SetWidgetToFocus(PauseMenuWidget->TakeWidget()));
			bShowMouseCursor = true;//�}�E�X�J�[�\����ON
		}
	}
}

void ACPP_MainGamePlayerController::OnPauseMenuGotoTitleButton()
{

}

void ACPP_MainGamePlayerController::OnPauseMenuCloseButton()
{
	if (PauseMenuWidget != nullptr)
	{
		PauseMenuWidget->CloseMenu();

		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
}