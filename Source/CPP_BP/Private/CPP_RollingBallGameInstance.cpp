// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_RollingBallGameInstance.h"

void UCPP_RollingBallGameInstance::Initialize()
{
	// �����l���������N���X��DefaultObject���擾����
	const UCPP_RollingBallGameInstance* DefaultObject = GetDefault<UCPP_RollingBallGameInstance>();

	// �����l��ݒ肷��
	this->TotalCoints = DefaultObject->TotalCoints;
	this->TotalLifes = DefaultObject->TotalLifes;
}