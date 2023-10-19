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
	//コンストラクタ
	ACPP_ItemCoin();

	//コインの取得枚数
	UPROPERTY(EditAnywhere, Category = "Item")
	int32 Number = 1;

protected:
	//アイテムを取得する処理をOverrideする
	void GetItem() override;
};
