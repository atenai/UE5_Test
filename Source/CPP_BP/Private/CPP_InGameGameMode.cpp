// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InGameGameMode.h"
#include "CPP_BallPlayer.h"//#include "(�v���C���[�ƂȂ�Class�̃w�b�_�[�t�@�C��)"

//�R���X�g���N�^
ACPP_InGameGameMode::ACPP_InGameGameMode()
{
	//DefaultPawnClass = (�v���C���[�ƂȂ�Class)::StaticClass();
	DefaultPawnClass = ACPP_BallPlayer::StaticClass();
}