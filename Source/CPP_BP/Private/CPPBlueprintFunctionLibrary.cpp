// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPBlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

void UCPPBlueprintFunctionLibrary::PrintHello()
{
	// Heloを出力する
	UKismetSystemLibrary::PrintString(NULL, FString::Printf(TEXT("Hello")), true, true, FColor::Orange, 10.f, TEXT("None"));
}

int UCPPBlueprintFunctionLibrary::Sum(const int A, const int B)
{
	return A + B;
}