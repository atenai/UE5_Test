// Fill out your copyright notice in the Description page of Project Settings.//消すと壊れる


#include "MySomeCPPActor.h"
#include "Kismet/KismetSystemLibrary.h"

//コンストラクタ
AMySomeCPPActor::AMySomeCPPActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

//スタート関数
void AMySomeCPPActor::BeginPlay()
{
	Super::BeginPlay();
}

//アップデート関数
void AMySomeCPPActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//その他の自作関数
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