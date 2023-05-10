// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // ’Ç‰Á
#include "Kismet/KismetMathLibrary.h" // ’Ç‰Á

ACPPCalculation::ACPPCalculation()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPCalculation::BeginPlay()
{
	Super::BeginPlay();
	
	// •Ï”‚ðì¬‚·‚é
	FString Message = "C++ Hello World!";

	// PrintStringƒm[ƒh‚Æ“¯‚¶ˆ—
	// UKismetSystemLibraryƒNƒ‰ƒX‚ÌPrintStringŠÖ”‚ðŒÄ‚Ño‚·
	UKismetSystemLibrary::PrintString(
		this
		, Message
		, true
		, true
		, TextColor// Text‚ÌƒJƒ‰[î•ñ‚É•Ï”TextColor‚ðÝ’è
		, Duration
		, TEXT("None"));

	// Add(‘«‚µŽZ)‚Ìˆ—
	//A + B‚ÌŒvŽZ
	int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
	//ã‚ÅŒvŽZ‚µ‚½”’l‚ðintŒ^‚©‚çstringŒ^‚É•ÏX
	FString StrResultAdd = UKismetStringLibrary::Conv_IntToString(ResultAdd);
	//stringŒ^‚É•ÏX‚µ‚½•¶Žš—ñ‚ð•`‰æ
	UKismetSystemLibrary::PrintString(
		this
		, StrResultAdd
		, true
		, true
		, FColor::Red
		, Duration
		, TEXT("None"));

	// Subtract(ˆø‚«ŽZ)‚Ìˆ—
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

	// Multiply(Š|‚¯ŽZ)‚Ìˆ—
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

	// Divide(Š„‚èŽZ)‚Ìˆ—
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

	// Divide(Š„‚èŽZ)‚Ìˆ—(int > float)
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

