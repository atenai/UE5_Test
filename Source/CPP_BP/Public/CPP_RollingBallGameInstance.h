// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CPP_RollingBallGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPP_RollingBallGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	//�擾�����R�C���̐�
	int32 TotalCoints = 0;

	//Player��Life
	int32 TotalLifes = 3;

	//����������
	void Initialize();
};
