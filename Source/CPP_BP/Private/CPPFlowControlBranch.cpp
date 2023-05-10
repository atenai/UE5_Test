// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlBranch.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPFlowControlBranch::ACPPFlowControlBranch()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPFlowControlBranch::BeginPlay()
{
	Super::BeginPlay();

	// ïœêîÇçÏê¨Ç∑ÇÈ
	//FString Message = "FlowControl";

	FString Message = (IsBlueprint) ? "Blueprint Hello World!" : "C++ Hello World!";

	if (IsPrintHello)
	//if (NumA == NumB)
	//if (10 < NumC && NumC <= 30)
	{
		// PrintStringÉmÅ[ÉhÇ∆ìØÇ∂èàóù
		// UKismetSystemLibraryÉNÉâÉXÇÃPrintStringä÷êîÇåƒÇ—èoÇ∑
		UKismetSystemLibrary::PrintString(
			this
			, Message
			, true
			, true
			, TextColor// TextÇÃÉJÉâÅ[èÓïÒÇ…ïœêîTextColorÇê›íË
			, Duration
			, TEXT("None"));
	}
	else
	{
		if (CalcType == 0) {
			// Add(ë´ÇµéZ)ÇÃèàóù
			int32 ResultAdd = CalcVarA + CalcVarB;
			FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
			UKismetSystemLibrary::PrintString(
				this
				, StrResultAdd
				, true
				, true
				, FColor::Red
				, Duration
				, TEXT("None"));
		}
		else if(CalcType == 1)
		{
			// Subtract(à¯Ç´éZ)ÇÃèàóù
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
		}
		else if (CalcType == 2) 
		{
			// Multiply(ä|ÇØéZ)ÇÃèàóù
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
		}
		else if(CalcType == 3)
		{
			// Divide(äÑÇËéZ)ÇÃèàóù
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
		}
	}
}

void ACPPFlowControlBranch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

