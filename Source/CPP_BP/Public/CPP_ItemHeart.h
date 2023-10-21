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
	//コンストラクタ
	ACPP_ItemHeart();

	//回復量
	UPROPERTY(EditAnywhere, Category = "Item")
	float HealValue = 25.0f;

protected:
	//アイテムを取得する処理をOverrideする
	void GetItem() override;
};