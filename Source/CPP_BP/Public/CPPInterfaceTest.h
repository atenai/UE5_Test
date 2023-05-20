// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPInterface.h"
#include "CPPInterfaceTest.generated.h"

UCLASS()
class CPP_BP_API ACPPInterfaceTest : public AActor, public ICPPInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPInterfaceTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// �����Ɩ߂�l���Ȃ������o�֐�
	virtual void PrintHello() override;

	// �����Ɩ߂�l�����郁���o�֐�
	virtual int Add(int A, int B) override;
};