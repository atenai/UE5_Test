// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlLoop.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACPPFlowControlLoop::ACPPFlowControlLoop()
{
	PrimaryActorTick.bCanEverTick = true;

	// Event Dispathcer[OnPrintHello]��Custom Event[PrintHello]���o�C���h����
	OnPrintHello.AddDynamic(this, &ACPPFlowControlLoop::PrintHello);
}

int32 ACPPFlowControlLoop::Sum(int32 A, int32 B)
{
	return A + B;
}

void ACPPFlowControlLoop::BeginPlay()
{
	Super::BeginPlay();

	SetupInput();

	if (IsPrintHello)
	{
		// Hello World!���o�͂��鏈��
		PrintHello();
	}
	else
	{
		// �v�Z���ʂ��o�͂��鏈��
		PressedActionPrintCalcResult();
	}
}

void ACPPFlowControlLoop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPFlowControlLoop::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
	case ECPPCalcType::Add:
	{
		// Add(�����Z)�̏���
		int32 ResultAdd = Sum(CalcVarA, CalcVarB);
		FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultAdd
			, true
			, true
			, FColor::Red
			, Duration
			, TEXT("None"));
		break;
	}
	case ECPPCalcType::Subtract:
	{
		// Subtract(�����Z)�̏���
		int32 ResultSubtract = CalcVarA - CalcVarB;
		FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultSubtract
			, true
			, true
			, FColor::Yellow
			, Duration
			, TEXT("None"));
		break;
	}
	case ECPPCalcType::Multiply:
	{
		// Multiply(�|���Z)�̏���
		int32 ResultMultiply = CalcVarA * CalcVarB;
		FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultMultiply
			, true
			, true
			, FColor::Green
			, Duration
			, TEXT("None"));
		break;
	}
	case ECPPCalcType::Divide:
	{
		// Divide(����Z)�̏���
		float ResultDivide = (float)CalcVarA / (float)CalcVarB;
		FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultDivide
			, true
			, true
			, FColor::Blue
			, Duration
			, TEXT("None"));
		break;
	}
	}
}

void ACPPFlowControlLoop::SetupInput()
{
	// ���͂�L���ɂ���
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// H�L�[��Pressed��Released���o�C���h����
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPFlowControlLoop::PressedH);

	// ActionMappings�ɐݒ肵��Action���o�C���h����
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPFlowControlLoop::PressedActionPrintCalcResult);
}

void ACPPFlowControlLoop::PressedH()
{
	// Event Dispathcer[OnPrintHello]���R�[������
	OnPrintHello.Broadcast();
}

void ACPPFlowControlLoop::PressedActionPrintCalcResult()
{
	// �v�Z���ʂ��o�͂��鏈��
	PrintCalcResult(CalcTypes[TypeIndex], CalcVarA, CalcVarB, Duration);

	TypeIndex++;
	TypeIndex = TypeIndex % CalcTypes.Num();
}

void ACPPFlowControlLoop::PrintHello()
{
	//int32 randomIndex = FMath::RandRange(0, Messages.Num() - 1);

	//// 1�s�ŏ����Ȃ� 
	//// Messages[FMath::RandRange(0, Messages.Num() - 1)]

	//// Hello World!���o�͂��鏈��
	//UKismetSystemLibrary::PrintString(this, Messages[randomIndex], true, true, TextColor, Duration, TEXT("None"));

	//int32 FirstIndex = 0;
	//int32 LastIndex = 4;

	////5�񃋁[�v
	//// for loop
	//for (int32 index = FirstIndex; index <= LastIndex; index++)
	//{
	//	// index�̒l���o�͂���
	//	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%d"), index), true, true, TextColor, Duration, TEXT("None"));//���[�v�Ԗڂ�\��
	//}
	//// Completed��PrintString�ŏo�͂���
	//UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));

	//int32 FirstIndex = 0;
	//int32 LastIndex = Messages.Num() - 1;

	//// for loop
	//for (int32 index = FirstIndex; index <= LastIndex; index++)
	//{
	//	// Messages�̒l���o�͂���
	//	UKismetSystemLibrary::PrintString(this, Messages[index], true, true, TextColor, Duration, TEXT("None"));
	//}
	//// Completed��PrintString�ŏo�͂���
	//UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));

	//int32 FirstIndex = 0;
	//int32 LastIndex = Messages.Num() - 1;

	//// for loop
	//for (int32 index = FirstIndex; index <= LastIndex; index++)
	//{
	//	// �������"Bonjour"���܂܂�Ă��邩
	//	if (Messages[index].Contains(TEXT("Bonjour")))
	//	{
	//		// True�Ȃ�Loop�𔲂���
	//		break;
	//	}

	//	// Messages�̒l���o�͂���
	//	UKismetSystemLibrary::PrintString(this, Messages[index], true, true, TextColor, Duration, TEXT("None"));
	//}
	//// Completed��PrintString�ŏo�͂���
	//UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));

	//int32 FirstIndex = 0;
	//int32 LastIndex = Messages.Num() - 1;

	//// for loop
	//for (int32 index = FirstIndex; index <= LastIndex; index++)
	//{
	//	// �������"Bonjour"���܂܂�Ă��邩
	//	if (Messages[index].Contains(TEXT("Bonjour")))
	//	{
	//		// True�Ȃ�Loop�𑱂���
	//		continue;
	//	}

	//	// Messages�̒l���o�͂���
	//	UKismetSystemLibrary::PrintString(this, Messages[index], true, true, TextColor, Duration, TEXT("None"));
	//}
	//// Completed��PrintString�ŏo�͂���
	//UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));

	//// C++�ł�For Each Loop with Break
	//for (FString Message : Messages)
	//{
	//	// �������"Bonjour"���܂܂�Ă��邩
	//	if (Message.Contains(TEXT("Bonjour")))
	//	{
	//		// True�Ȃ�Loop�𑱂���
	//		break;
	//	}
	//	// Messages�̒l���o�͂���
	//	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration, TEXT("None"));
	//}
	//// Completed��PrintString�ŏo�͂���
	//UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));

	bool NotBonjour = true;
	int32 HelloIndex = 0;

	while (NotBonjour)
	{
		// �������"Bonjour"���܂܂�Ă��邩
		if (Messages[HelloIndex].Contains(TEXT("Bonjour")))
		{
			// While Loop�̏�����false�ɐݒ肷��
			NotBonjour = false;
		}
		else
		{
			// Messages�̒l���o�͂���
			UKismetSystemLibrary::PrintString(this, Messages[HelloIndex], true, true, TextColor, Duration, TEXT("None"));
		}
		// HelloIndex���C���N�������g
		HelloIndex++;
	}

	// Completed��PrintString�ŏo�͂���
	UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));
}