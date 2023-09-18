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

void UCPP_DataTypeLibrary::MakeDifference(const FTransform& In1, const FTransform& In2, FTransform& Out)
{
	Out.SetLocation(In1.GetLocation() - In2.GetLocation());
	Out.SetRotation(In1.GetRotation() - In2.GetRotation());
	Out.SetScale3D(In1.GetScale3D() - In2.GetScale3D());
}

void UCPP_DataTypeLibrary::RepeatString(const FString& StringToRepeat, int32 RepeatCount, FString& Out)
{
	Out = "";

	for (int32 i = 1; i <= RepeatCount; i++)
	{
		Out += StringToRepeat;
	}
}