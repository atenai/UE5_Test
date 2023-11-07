// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainGameModeBase.h"
#include "UObject/ConstructorHelpers.h"

ACPP_MainGameModeBase::ACPP_MainGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//�u���[�v�����g�̃L�����N�^�[���擾
	static ConstructorHelpers::FClassFinder<APawn> PawnClass(TEXT("/Game/Blueprints/BP_PlayerPawn"));

	//�擾�ɐ��������璆�g�����s����
	if (PawnClass.Succeeded())
	{
		//�L�����N�^�[���Q�[�����[�h�̃f�t�H���g�|�[���N���X�ɐݒ�
		DefaultPawnClass = PawnClass.Class;
	}
}