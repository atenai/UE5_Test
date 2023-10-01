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
    UFUNCTION(BlueprintCallable, Category = "KashiwabaraC++")
    void TestPrint(int testNumber);

    //BlueprintCallable�͏�����Input��Output�̓����Əo��������m�[�h�ɂȂ�
    UFUNCTION(BlueprintCallable, Category = "KashiwabaraC++")
    static int StaticSetAddNumber(int number);//static������Ƃǂ̃u���[�v�����g������Ăяo����

    //BlueprintPure�͒l���������m�[�h�ɂȂ�(������)
    UFUNCTION(BlueprintPure, Category = "KashiwabaraC++")
    static int StaticGet2023();

    UFUNCTION(BlueprintPure, Category = "KashiwabaraC++")
    float Get10();

	UPROPERTY(EditAnywhere)
    float num10 = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Reference|Edit")
	float NumEditAnywhere;

	UPROPERTY(EditDefaultsOnly, Category = "Reference|Edit")
	float NumEditDefaultsOnly;

	UPROPERTY(EditInstanceOnly, Category = "Reference|Edit")
	float NumEditInstanceOnly;

	UPROPERTY(VisibleAnywhere, Category = "Reference|Visible")
	float NumVisibleAnywhere;

	UPROPERTY(VisibleDefaultsOnly, Category = "Reference|Visible")
	float NumVisibleDefaultsOnly;

	UPROPERTY(VisibleInstanceOnly, Category = "Reference|Visible")
	float NumVisibleInstanceOnly;

    UPROPERTY(EditAnywhere, meta = (EditCondition = "bEditCondition"), Category = "Reference|Edit")
	float NumEditCondition;

	UPROPERTY()
	bool bEditCondition;
    
    UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "Reference")
	float NumAdvancedDisplay;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ReadWrite")
	float NumBlueprintReadOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ReadWrite")
	float NumBlueprintReadWrite;

    /* Description String */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Description")
	float NumDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "-10.0", ClampMax = "10.0"), Category = "ValueRange")
	float NumValueRange;
};