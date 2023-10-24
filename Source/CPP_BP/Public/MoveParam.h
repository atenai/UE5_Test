// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MovePattern.h"
#include "CoreMinimal.h"
#include "MoveParam.generated.h"

USTRUCT(BlueprintType) 
struct FMoveParam
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EMovePattern Pattern;

	//EditConditionは""で囲われた条件式をもとに編集可否を切り替える
	UPROPERTY(EditAnywhere, meta = (EditCondition = "Pattern != EMovePattern::Static"))
	FVector Speed;

	//InlineEditConditionToggleはチェックボックスのON/OFFで編集可否を切り替える
	UPROPERTY(EditAnywhere, meta = (InlineEditConditionToggle))
	bool bLookTarget;

	//EditConditionは""で囲われた条件式をもとに編集可否を切り替える（つまりbLookTargetがtrueなら編集可能）
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bLookTarget"))
	TObjectPtr<AActor> TargetActor;
};
