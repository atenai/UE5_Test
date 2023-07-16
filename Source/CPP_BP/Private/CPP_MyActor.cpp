// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MyActor.h"

// Sets default values
ACPP_MyActor::ACPP_MyActor()
{
 	//�e�N���X�ł��� AActor �N���X�̃����o�ϐ��ɑ΂��A�f�t�H���g�l��ݒ肵�Ă��܂��BTick �̓� ��𐧌䂷�邽�߂̕ϐ��ł����A���̂܂܎c���Ă����Ă����Ă��������B
	PrimaryActorTick.bCanEverTick = true;

	ParentMemberVar = 100.0f;

	MemberVar1 = 0.0f; 
	MemberVar2 = false;
}

// Called when the game starts or when spawned
void ACPP_MyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_MyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Func2(1.0, false);
	this->Func2(1.0, false);
	UCPP_MyLibrary::Func10();

	MemberVar += DeltaTime;
}

void ACPP_MyActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	MemberVar = 0.0f;
}

void ACPP_MyActor::Func(double In1, double In2, double& Out1, double& Out2)
{
	double LocalVar;

	LocalVar = In1 + In2;
	Out1 = LocalVar / 2.0f;
	Out2 = LocalVar * 2.0f;
}

void ACPP_MyActor::Func2(double In1, bool isIn2)
{

}

int32 ACPP_MyActor::PublicFunc()
{
	return 1;
}

void ACPP_MyActor::ProtectedFunc()
{

}