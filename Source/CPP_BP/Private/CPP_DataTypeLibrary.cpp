// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DataTypeLibrary.h"

void  UCPP_DataTypeLibrary::ComponentWiseSquared(FVector In, FVector& Out)
{
	Out = In * In;
}

void UCPP_DataTypeLibrary::AddRotationAngle(FRotator In, double X, double Y, double Z, FRotator& Out)
{
	Out.Roll = In.Roll + X;
	Out.Pitch = In.Pitch + Y;
	Out.Yaw = In.Yaw + Z;
}