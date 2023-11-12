// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_MainGamePlayerController.generated.h"


UCLASS()
class CPP_BP_API ACPP_MainGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

	virtual void AddPitchInput(float Val) override;	
};
