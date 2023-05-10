// Fill out your copyright notice in the Description page of Project Settings.//�����Ɖ���

#pragma once//�����Ɖ���

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySomeCPPActor.generated.h"//.generated.h�������z�͕K����ԍŌ�ɂ���K�v������

UCLASS()
class CPP_BP_API AMySomeCPPActor : public AActor
{
	GENERATED_BODY()
	
public:	
    //�R���X�g���N�^�A����������Ɖ���
	AMySomeCPPActor();

protected:
    //�X�^�[�g�֐�
	virtual void BeginPlay() override;

private:
    //�ϐ�

    float num10 = 10.0f;


public:	
    //�A�b�v�f�[�g�֐�
	virtual void Tick(float DeltaTime) override;


    static const int year = 2023;

    //�֐�

    //UFUNCTION(Unreal�֐��̈Ӗ�)�����鎖�ł��̒���ɐ錾���ꂽ�֐����A�����A���G���W�����̃u���[�v�����g�G�f�B�^����ݒ�ł���悤�ɂȂ�܂��B
    //��������BlueprintCallable��BlueprintPure������
    //BlueprintCallable�͏�����Input��Output�̓����Əo��������m�[�h�ɂȂ�
    //BlueprintPure�͒l���������m�[�h�ɂȂ�(������)
    //��������Category = "TestC++"�́u "TestC++"�v�̕����͎��R�ɖ��O�����邱�Ƃ��ł��A���̖��O�̃J�e�S���[�Ɋ֐��������
    UFUNCTION(BlueprintCallable, Category = "TestC++")
        void TestPrint();

    //BlueprintCallable�͏�����Input��Output�̓����Əo��������m�[�h�ɂȂ�
    UFUNCTION(BlueprintCallable, Category = "TestC++")
        static int StaticSetAddNumber(int number);//static������Ƃǂ̃u���[�v�����g������Ăяo����

    //BlueprintPure�͒l���������m�[�h�ɂȂ�(������)
    UFUNCTION(BlueprintPure, Category = "TestC++")
        static int StaticGet2023();

    UFUNCTION(BlueprintPure, Category = "TestC++")
        float Get10();
};