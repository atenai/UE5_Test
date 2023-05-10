// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlSwitch.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

ACPPFlowControlSwitch::ACPPFlowControlSwitch()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPFlowControlSwitch::BeginPlay()
{
	Super::BeginPlay();

	// •Ï”‚ğì¬‚·‚é
	FString Message = "Switch";

	if (IsPrintHello == true)
	{
		// PrintStringƒm[ƒh‚Æ“¯‚¶ˆ—
		// UKismetSystemLibraryƒNƒ‰ƒX‚ÌPrintStringŠÖ”‚ğŒÄ‚Ño‚·
		UKismetSystemLibrary::PrintString(
			this
			, Message
			, true
			, true
			, TextColor// Text‚ÌƒJƒ‰[î•ñ‚É•Ï”TextColor‚ğİ’è
			, Duration
			, TEXT("None"));
	}
	else
	{
		//if (CalcType == 0)
		//{
		//	// Add(‘«‚µZ)‚Ìˆ—
		//	int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
		//	FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
		//	UKismetSystemLibrary::PrintString(
		//		this
		//		, StrResultAdd
		//		, true
		//		, true
		//		, FColor::Red
		//		, Duration
		//		, TEXT("None"));
		//}
		//else if (CalcType == 1)
		//{
		//	// Subtract(ˆø‚«Z)‚Ìˆ—
		//	int32 ResultSubtract = CalcVarA - CalcVarB;
		//	FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
		//	UKismetSystemLibrary::PrintString(
		//		this
		//		, StrResultSubtract
		//		, true
		//		, true
		//		, FColor::Yellow
		//		, Duration
		//		, TEXT("None"));
		//}
		//else if (CalcType == 2)
		//{
		//	// Multiply(Š|‚¯Z)‚Ìˆ—
		//	int32 ResultMultiply = CalcVarA * CalcVarB;
		//	FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
		//	UKismetSystemLibrary::PrintString(
		//		this
		//		, StrResultMultiply
		//		, true
		//		, true
		//		, FColor::Green
		//		, Duration
		//		, TEXT("None"));
		//}
		//else
		//{
		//	// Divide(Š„‚èZ)‚Ìˆ—
		//	float ResultDivide = (float)CalcVarA / (float)CalcVarB;
		//	FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
		//	UKismetSystemLibrary::PrintString(
		//		this
		//		, StrResultDivide
		//		, true
		//		, true
		//		, FColor::Blue
		//		, Duration
		//		, TEXT("None"));
		//}

		switch (CalcType)
		{
			case 0:
			{
				// Add(‘«‚µZ)‚Ìˆ—
				int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
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
			case 1:
			{
				// Subtract(ˆø‚«Z)‚Ìˆ—
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
			case 2:
			{
				// Multiply(Š|‚¯Z)‚Ìˆ—
				int32 ResultMultiply = CalcVarA * CalcVarB;
				FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
				UKismetSystemLibrary::PrintString(
					this
					, StrResultMultiply
					, true
					, true
					, FColor::Black
					, Duration
					, TEXT("None"));
				break;
			}
			default:
			{
				// Divide(Š„‚èZ)‚Ìˆ—
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
}

void ACPPFlowControlSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

