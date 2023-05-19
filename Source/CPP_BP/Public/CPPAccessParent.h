// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAccessParent.generated.h"

UCLASS()
class CPP_BP_API ACPPAccessParent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPAccessParent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// �e�N���X�̃����o�֐�(Public)
	UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint)
	void CallPublicFunc();

	// �e�N���X�̃f�[�^�����o(Public)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	int VarPublicNum = 10;

protected:

	// �e�N���X�̃����o�֐�(Protected)
	UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint)
	void CallProtectedFunc();

	// �e�N���X�̃f�[�^�����o(Protected)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	int VarProtectedNum = 20;

private:

	// �e�N���X�̃����o�֐�(Private)
	//UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint)
	void CallPrivateFunc();

	// �e�N���X�̃f�[�^�����o(Private)
	//UPROPERTY(EditAnywhere, Category = Default)
	int VarPrivateNum = 30;
};