// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVariable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // �ǉ�

ACPPVariable::ACPPVariable()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPVariable::BeginPlay()
{
	Super::BeginPlay();

	// �ϐ����쐬����
	FString Message = "Variable";

	// Duration�ɕʂ̒l��ݒ肷��
	//Duration = 30.0f;

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Yellow, Duration, TEXT("None"));
	
	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(
		this
		, UKismetStringLibrary::Conv_DoubleToString(Duration) // Duration��float����FString�ɕϊ�����
		, true
		, true
		, TextColor
		, Duration
		, TEXT("None"));
}

void ACPPVariable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

