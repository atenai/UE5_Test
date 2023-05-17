// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAccessOther.h"
#include "CPPAccessParent.h"//�A�N�Z�X�������A�N�^�[�̃w�b�_�[���C���N���[�h
#include "Kismet/GameplayStatics.h"//�ق��̃A�N�^�[��T�����߂ɕK�v�ȃw�b�_�[���C���N���[�h

// Sets default values
ACPPAccessOther::ACPPAccessOther()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPAccessOther::BeginPlay()
{
	Super::BeginPlay();
	
	// Viewport�ɂ���ACPPAccessParent��T��
	AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), ACPPAccessParent::StaticClass());

	// �擾����AActor����ACPPAccessParent�ɕϊ����� 
	ACPPAccessParent* CPPAccessParent = Cast<ACPPAccessParent>(FoundActor);

	// CPPAccessParent�̃f�[�^�����o(Public)��ύX����
	CPPAccessParent->VarPublicNum = 1000;

	// CPPAccessParent�̃f�[�^�����o(Protected)��ύX����
	//CPPAccessParent->VarProtectedNum = 2000;

	// CPPAccessParent�̃f�[�^�����o(Private)��ύX����
	//CPPAccessParent->VarPrivateNum = 3000;

	// CPPAccessParent�̃����o�֐�(Public)���Ăяo��
	CPPAccessParent->CallPublicFunc();

	// CPPAccessParent�̃����o�֐�(Protected)���Ăяo��
	//CPPAccessParent->CallProtectedFunc();

	// CPPAccessParent�̃����o�֐�(Private)���Ăяo��
	//CPPAccessParent->CallPrivateFunc();
}

// Called every frame
void ACPPAccessOther::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

