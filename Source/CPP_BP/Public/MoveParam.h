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

	//EditCondition��""�ň͂�ꂽ�����������ƂɕҏW�ۂ�؂�ւ���
	UPROPERTY(EditAnywhere, meta = (EditCondition = "Pattern != EMovePattern::Static"))
	FVector Speed;

	//InlineEditConditionToggle�̓`�F�b�N�{�b�N�X��ON/OFF�ŕҏW�ۂ�؂�ւ���
	UPROPERTY(EditAnywhere, meta = (InlineEditConditionToggle))
	bool bLookTarget;

	//EditCondition��""�ň͂�ꂽ�����������ƂɕҏW�ۂ�؂�ւ���i�܂�bLookTarget��true�Ȃ�ҏW�\�j
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bLookTarget"))
	TObjectPtr<AActor> TargetActor;
};
