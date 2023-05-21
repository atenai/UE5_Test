// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAbstractChild.h"
#include "Kismet/KismetSystemLibrary.h"

void ACPPAbstractChild::Greeting(FString message)
{
	UKismetSystemLibrary::PrintString(this, message, true, true, FColor::Red, 10.f, TEXT("None"));
}