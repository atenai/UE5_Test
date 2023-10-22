// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_RollingBallGameInstance.h"

void UCPP_RollingBallGameInstance::Initialize()
{
	// 初期値を持つ同じクラスのDefaultObjectを取得する
	const UCPP_RollingBallGameInstance* DefaultObject = GetDefault<UCPP_RollingBallGameInstance>();

	// 初期値を設定する
	this->TotalCoints = DefaultObject->TotalCoints;
	this->TotalLifes = DefaultObject->TotalLifes;
}