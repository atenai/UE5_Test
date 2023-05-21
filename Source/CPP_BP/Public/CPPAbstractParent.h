// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAbstractParent.generated.h"

UCLASS(Abstract)//���ۃN���X�̏ꍇ�͈�����Abstract������
class CPP_BP_API ACPPAbstractParent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPAbstractParent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

		// �h���N���X�Œl��ݒ肷��
	UPROPERTY(EditAnywhere, Category = Default)
	FString GreetingMessage;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ���A����
	virtual void Greeting(FString message) PURE_VIRTUAL(ACPPAbstractParent::Greeting, );//�������z�֐��ɂ́APURE_VIRTUAL���w�肵�܂��B
	// �߂�l������ꍇ
	//virtual int sum(int A, intB) PURE_VIRTUAL(ACPPAbstractParent::sum, return 0;);
};
