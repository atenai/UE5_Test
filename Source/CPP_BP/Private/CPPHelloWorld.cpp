// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPHelloWorld.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPHelloWorld::ACPPHelloWorld()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPHelloWorld::BeginPlay()
{
	Super::BeginPlay();

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, "C++ Hello World!", true, true, FColor::Cyan, 20.f, TEXT("None"));

	UKismetSystemLibrary::PrintString(this, "C++ Hello World! Change", true, true, FColor::Red, 10.f, TEXT("None"));

	// Output Log�ɕ�������o�͂���}�N��
	UE_LOG(LogTemp, Display, TEXT("Display Message"));
	UE_LOG(LogTemp, Warning, TEXT("Warning Message"));
	UE_LOG(LogTemp, Error, TEXT("Error Message"));

	// Viewport�̍���ɕ�������o�͂���֐�
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, "C++ Hello World! GEngine", true, FVector2D(2.0f, 2.0f));
}

void ACPPHelloWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

