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