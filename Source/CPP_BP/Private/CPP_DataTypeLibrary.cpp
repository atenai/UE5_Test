// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DataTypeLibrary.h"

void  UCPP_DataTypeLibrary::ComponentWiseSquared(FVector In, FVector& Out)
{
	Out = In * In;
}