// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestKashiwabara.generated.h"

UCLASS()
class CPP_BP_API ATestKashiwabara : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestKashiwabara();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


private:

	FString test = "Kashiwabara";

	const FLinearColor TextColor = FColor::Magenta;
};
