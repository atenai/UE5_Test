// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // �ǉ�
#include "Kismet/KismetMathLibrary.h" // �ǉ�

ACPPCalculation::ACPPCalculation()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPCalculation::BeginPlay()
{
	Super::BeginPlay();
	
	// �ϐ����쐬����
	FString Message = "C++ Hello World!";

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(
		this
		, Message
		, true
		, true
		, TextColor// Text�̃J���[���ɕϐ�TextColor��ݒ�
		, Duration
		, TEXT("None"));

	// Add(�����Z)�̏���
	//A + B�̌v�Z
	int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
	//��Ōv�Z�������l��int�^����string�^�ɕύX
	FString StrResultAdd = UKismetStringLibrary::Conv_IntToString(ResultAdd);
	//string�^�ɕύX�����������`��
	UKismetSystemLibrary::PrintString(
		this
		, StrResultAdd
		, true
		, true
		, FColor::Red
		, Duration
		, TEXT("None"));

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

	// Divide(����Z)�̏���
	int32 ResultDivide = CalcVarA / CalcVarB;
	FString StrResultDivide = FString::Printf(TEXT("%d"), ResultDivide);
	UKismetSystemLibrary::PrintString(
		this
		, StrResultDivide
		, true
		, true
		, FColor::Blue
		, Duration
		, TEXT("None"));

	// Divide(����Z)�̏���(int > float)
	float ResultDivide2 = (float)CalcVarA / (float)CalcVarB;
	FString StrResultDivide2 = FString::Printf(TEXT("%f"), ResultDivide2);
	UKismetSystemLibrary::PrintString(
		this
		, StrResultDivide2
		, true
		, true
		, FColor::Blue
		, Duration
		, TEXT("None"));
}

void ACPPCalculation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

