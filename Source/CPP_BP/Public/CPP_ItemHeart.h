// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemBase.h"
#include "CPP_ItemHeart.generated.h"


UCLASS()
class CPP_BP_API ACPP_ItemHeart : public ACPP_ItemBase
{
	GENERATED_BODY()

public:
	//�R���X�g���N�^
	ACPP_ItemHeart();

	//�񕜗�
	UPROPERTY(EditAnywhere, Category = "Item")
	float HealValue = 25.0f;

protected:
	//�A�C�e�����擾���鏈����Override����
	void GetItem() override;
};