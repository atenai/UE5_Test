// Fill out your copyright notice in the Description page of Project Settings.//�����Ɖ���


#include "MySomeCPPActor.h"
#include "Kismet/KismetSystemLibrary.h"

//�R���X�g���N�^
AMySomeCPPActor::AMySomeCPPActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

//�X�^�[�g�֐�
void AMySomeCPPActor::BeginPlay()
{
	Super::BeginPlay();
}

//�A�b�v�f�[�g�֐�
void AMySomeCPPActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//���̑��̎���֐�
void AMySomeCPPActor::TestPrint()
{
	UKismetSystemLibrary::PrintString(this, "TestC++", true, true, FColor::Red, 20.f, TEXT("None"));
}

int AMySomeCPPActor::StaticSetAddNumber(int number)
{
	static int count = 10;
	return count + number;
}

int AMySomeCPPActor::StaticGet2023()
{
	return year;
}

float AMySomeCPPActor::Get10()
{
    return num10;
}