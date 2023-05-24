// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPEnhancedInputTest.h"
#include "Kismet/KismetSystemLibrary.h" // �ǉ�
#include "Kismet/GameplayStatics.h" // �ǉ�
#include "Components/InputComponent.h" // �ǉ�
#include "EnhancedInputComponent.h" // �ǉ�
#include "EnhancedInputSubsystems.h" // �ǉ�

class UInputMappingContext;

// Sets default values
ACPPEnhancedInputTest::ACPPEnhancedInputTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Input Action��Ǎ�
	ActionInput = LoadObject<UInputAction>(NULL, TEXT("/Game/Input/Actions/IA_Action"), NULL, LOAD_None, NULL);//IA_Action������t�H���_�[�̈ʒu���L�q����K�v������
	AxisInput = LoadObject<UInputAction>(NULL, TEXT("/Game/Input/Actions/IA_Axis"), NULL, LOAD_None, NULL);//IA_Axis������t�H���_�[�̈ʒu���L�q����K�v������

	// Input Mapping Context��Ǎ�
	DefaultMappingContext = LoadObject<UInputMappingContext>(NULL, TEXT("/Game/Input/IMC_Default"), NULL, LOAD_None, NULL);//IMC_Default������t�H���_�[�̈ʒu���L�q����K�v������

}

// Called when the game starts or when spawned
void ACPPEnhancedInputTest::BeginPlay()
{
	Super::BeginPlay();


	// Input�ݒ���s��
	SetupInput();
}

// Called every frame
void ACPPEnhancedInputTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPEnhancedInputTest::SetupInput()
{
	// PlayerController���擾����
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// ���͂�L���ɂ���
	EnableInput(controller);

	if (InputComponent)
	{
		// Set up action bindings
		if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {

			// Input Action
			EnhancedInputComponent->BindAction(ActionInput, ETriggerEvent::Triggered, this, &ACPPEnhancedInputTest::PressedAction);
			EnhancedInputComponent->BindAction(ActionInput, ETriggerEvent::Completed, this, &ACPPEnhancedInputTest::ReleasedAction);

			// Input Axis
			EnhancedInputComponent->BindAction(AxisInput, ETriggerEvent::Triggered, this, &ACPPEnhancedInputTest::PressedAxis);
		}

		// Input Mapping Context��o�^����
		if (APlayerController* PlayerController = Cast<APlayerController>(controller))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void ACPPEnhancedInputTest::PressedAction()
{
	if (!IsPressed)
	{
		// Pressed
		UKismetSystemLibrary::PrintString(this, TEXT("Pressed"), true, true, FColor::Cyan, 10.0f, TEXT("None"));

		// Press��Ԃɐݒ�
		IsPressed = true;
	}
}

void ACPPEnhancedInputTest::ReleasedAction()
{
	// Released
	UKismetSystemLibrary::PrintString(this, TEXT("Released"), true, true, FColor::Cyan, 10.0f, TEXT("None"));

	// Press��Ԃ�����
	IsPressed = false;
}

void ACPPEnhancedInputTest::PressedAxis(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D v = Value.Get<FVector2D>();

	// Axis Input Value
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("X:%f Y:%f"), v.X, v.Y), true, true, FColor::Cyan, 10.0f, TEXT("None"));
}