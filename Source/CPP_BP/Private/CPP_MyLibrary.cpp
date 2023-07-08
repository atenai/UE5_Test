// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MyLibrary.h"

double UCPP_MyLibrary::Func(double In1, double In2) 
{
	double LocalVar;

	LocalVar = In1 + In2;
	return LocalVar;//�o�͒l
}


//�����̌^�ɑ΂���&������Əo�͂ɂȂ�
//�iC++����return�ŏo�͒l��������ݒ�ł��Ȃ����A�����A���G���W���͕����̏o�͒l���m�[�h�ŏo�����Ƃ��ł����̍ۂɂ���&�����ĕ����̏o�͒l�����j
//�܂�return���Ƃ����ŏ������I��邪�����return���g��Ȃ��̂ŏ���������
void UCPP_MyLibrary::Func2(double In1, double In2, double& Out1, double& Out2)
{
	Out1 = In1 + In2;//Out1�̏o�͒l
	Out2 = In1 - In2;//Out2�̏o�͒l
}

//�Q�Ɠn���̋L�q���@�́A�����̌^�̑O�ɑ΂���UPARAM(ref)�����āA�����̌^�̌���&���L�q���A�����̖��O�ɓ��͖��i�Q�Ɠn���j���L�q����K�v������
void UCPP_MyLibrary::Func3(double In, UPARAM(ref) double& InRef)
{
	InRef = InRef + In;
}

//�Q�Ɠn���ł̕����̏o�͒l
void UCPP_MyLibrary::Func4(double In, UPARAM(ref) double& InRef, double& Out)
{

}

//const�Q�Ɠn���͈����̌^�̑O��const�����āA�����̌^�̌���&���L�q���A�����̖��O�ɓ��͖��i�Q�Ɠn���j���L�q����K�v������
//UPARAM(ref)�̋L�q�͕s�v
double UCPP_MyLibrary::Func5(double In, const double& InRef)
{
	return In + InRef;
}

//�����̉��Z�q
void UCPP_MyLibrary::Func6(double In1, double In2, double In3, double& Out)
{
	Out = (In1 + In2) * 2.0 - In3;

	//���Ƃ��΁AIn1 = 5.0, In2 = 3.0, In3 = 10.0 �̂Ƃ�
	//Out = (5.0 + 3.0) * 2.0 - 10.0 = 6.0 �ɂȂ�
}

//��������
double UCPP_MyLibrary::Func7(bool bCondA, bool bCondB, double Val1, double Val2)
{
	double LocalVar;

	if (bCondA && bCondB)//bCondA���^����bCondB���^�̏ꍇ�A���g�����s�����
	{
		LocalVar = Val1 + Val2;
	}
	else if (0.0 < Val2)//��̏������U�ł���A�Ȃ�����Val2��0.0���傫���ꍇ�A���g�����s�����
	{
		LocalVar = Val2;
	}
	else//��̏�������������U�ł���ꍇ�ɒ��g�����s�����
	{
		LocalVar = 0.0;
	}

	return LocalVar;//if�`else�̌�̏����͋��ʂōs����
}

//���[�v
int32 UCPP_MyLibrary::Func8(int32 In1, int32 In2)
{
	for (int32 Index = 0; Index < In1; Index++)
	{
		//Index�̏����l��0�Ƃ��AIndex < In1���^�ł�����胋�[�v����B
		//���[�v���ɁAIndex��1�����Z����B
		In2 += Index;//���[�v���ɁA���̏������s����B
	}
	return In2;
}

//�A�����A���G���W���̃��C�u�����֐��̌Ăяo��
void UCPP_MyLibrary::Func9()
{
	UKismetMathLibrary::FMin(10.0, 5.0);
}

void UCPP_MyLibrary::Func10()
{

}