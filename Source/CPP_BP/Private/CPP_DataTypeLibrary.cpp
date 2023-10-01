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

int32 UCPP_DataTypeLibrary::Sum(const TArray<int32>& Data)
{
	int32 Value = 0;

	for (int32 D : Data)
	{
		Value += D;
	}

	return Value;
}

void UCPP_DataTypeLibrary::MakeUnique(const TArray<FString>& In, TArray<FString>& Out)
{
	Out.Empty();

	TSet<FString> Unique(In);
	Out = Unique.Array();
}

void UCPP_DataTypeLibrary::MakeSquared(const TArray<int32>& Data, TMap<int32, int32>& Out)
{
	Out.Empty();

	for (int32 D : Data)
	{
		Out.Add(D, D * D);
	}
}

void UCPP_DataTypeLibrary::DistanceFromActor(const AActor* InActor, FVector Location, FVector& Distance)
{
	if (InActor != nullptr) //ポインタがnullではないか？の確認
	{
		Distance = InActor->GetActorLocation() - Location;
	}
}