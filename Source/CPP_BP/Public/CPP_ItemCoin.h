// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemBase.h"
#include "CPP_ItemCoin.generated.h"

UCLASS()
class CPP_BP_API ACPP_ItemCoin : public ACPP_ItemBase
{
	GENERATED_BODY()

public:
	//�R���X�g���N�^
	ACPP_ItemCoin();

	//�R�C���̎擾����
	UPROPERTY(EditAnywhere, Category = "Item")
	int32 Number = 1;

protected:
	//�A�C�e�����擾���鏈����Override����
	void GetItem() override;
};
