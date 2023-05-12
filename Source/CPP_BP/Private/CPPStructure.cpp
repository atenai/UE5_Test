// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPStructure.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACPPStructure::ACPPStructure()
{
	PrimaryActorTick.bCanEverTick = true;

	// Event Dispathcer[OnPrintHello]‚ÉCustom Event[PrintHello]‚ðƒoƒCƒ“ƒh‚·‚é
	OnPrintHello.AddDynamic(this, &ACPPStructure::PrintHello);
}

int32 ACPPStructure::Sum(int32 A, int32 B)
{
	return A + B;
}

void ACPPStructure::BeginPlay()
{
	Super::BeginPlay();

	SetupInput();

	if (IsPrintHello)
	{
		// Hello World!‚ðo—Í‚·‚éˆ—
		PrintHello();
	}
	else
	{
		// ŒvŽZŒ‹‰Ê‚ðo—Í‚·‚éˆ—
		PressedActionPrintCalcResult();
	}
}

void ACPPStructure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPStructure::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
	case ECPPCalcType::Add:
	{
		// Add(‘«‚µŽZ)‚Ìˆ—
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
		break;
	}
	case ECPPCalcType::Multiply:
	{
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
		break;
	}
	case ECPPCalcType::Divide:
	{
		// Divide(Š„‚èŽZ)‚Ìˆ—
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

void ACPPStructure::SetupInput()
{
	// “ü—Í‚ð—LŒø‚É‚·‚é
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// HƒL[‚ÌPressed‚ÆReleased‚ðƒoƒCƒ“ƒh‚·‚é
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPStructure::PressedH);

	// ActionMappings‚ÉÝ’è‚µ‚½Action‚ðƒoƒCƒ“ƒh‚·‚é
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPStructure::PressedActionPrintCalcResult);
}

void ACPPStructure::PressedH()
{
	// Event Dispathcer[OnPrintHello]‚ðƒR[ƒ‹‚·‚é
	OnPrintHello.Broadcast();
}

void ACPPStructure::PressedActionPrintCalcResult()
{
	// ŒvŽZŒ‹‰Ê‚ðo—Í‚·‚éˆ—
	//PrintCalcResult(CalcTypes[TypeIndex], CalcVarA, CalcVarB, Duration);

		// \‘¢‘Ì‚ðˆø”‚ÉŽ‚Á‚½ŒvŽZŒ‹‰Ê‚ðo—Í‚·‚éˆ—
	PrintCalcResultArgStructure(CalcInfos[TypeIndex], Duration);

	TypeIndex++;
	TypeIndex = TypeIndex % CalcTypes.Num();
}

void ACPPStructure::PrintHello()
{
	bool NotBonjour = true;
	int32 HelloIndex = 0;

	while (NotBonjour)
	{
		// •¶Žš—ñ‚É"Bonjour"‚ªŠÜ‚Ü‚ê‚Ä‚¢‚é‚©
		if (Messages[HelloIndex].Contains(TEXT("Bonjour")))
		{
			// While Loop‚ÌðŒ‚ðfalse‚ÉÝ’è‚·‚é
			NotBonjour = false;
		}
		else
		{
			// Messages‚Ì’l‚ðo—Í‚·‚é
			UKismetSystemLibrary::PrintString(this, Messages[HelloIndex], true, true, TextColor, Duration, TEXT("None"));
		}
		// HelloIndex‚ðƒCƒ“ƒNƒŠƒƒ“ƒg
		HelloIndex++;
	}

	// Completed‚ðPrintString‚Åo—Í‚·‚é
	UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));
}

void ACPPStructure::PrintCalcResultArgStructure(const FCPPCalcInfo& CalcInfo, const float PrintDuration)
{
	switch (CalcInfo.Type)
	{
	case ECPPCalcType::Add:
	{
		// Add(‘«‚µŽZ)‚Ìˆ—
		// ’l“n‚µ
		int32 ResultAdd = Sum(CalcInfo.NumA, CalcInfo.NumB);
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
		// Subtract(ˆø‚«ŽZ)‚Ìˆ—
		int32 ResultSubtract = CalcInfo.NumA - CalcInfo.NumB;
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
		// Multiply(Š|‚¯ŽZ)‚Ìˆ—
		int32 ResultMultiply = CalcInfo.NumA * CalcInfo.NumB;
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
		// Divide(Š„‚èŽZ)‚Ìˆ—(int > float)
		float ResultDivide = (float)CalcInfo.NumA / (float)CalcInfo.NumB;
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