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

	// SceneComponent���쐬����
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponent��RootComponent�ɐݒ肷��
	RootComponent = DefaultSceneRoot;

	// StaticMeshComponent���쐬����
	Comp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	Comp->SetStaticMesh(Mesh);

	// StaticMeshComponent��RootComponent��Attach����
	Comp->SetupAttachment(RootComponent);//(Component�̕ϐ���)->SetupAttachment( (Attach�������e�ƂȂ�Component�̕ϐ���)�@);
}

// Called when the game starts or when spawned
void ACPP_MyActor::BeginPlay()
{
	Super::BeginPlay();

	Func3();
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

void ACPP_MyActor::Func3()
{
	FCPP_MyStruct strVar = { 5, true, 10.0f };

	int32 ResultVar1 = strVar.Var1;
	FString StrResultVar1 = FString::Printf(TEXT("%d"), ResultVar1);
	UKismetSystemLibrary::PrintString(this, StrResultVar1, true, true, FColor::Green, 20.f, TEXT("None"));

	if (strVar.Var2 == true)
	{
		float ResultVar3 = strVar.Var3;
		FString StrResultVar3 = FString::Printf(TEXT("%f"), ResultVar3);
		UKismetSystemLibrary::PrintString(this, StrResultVar3, true, true, FColor::Yellow, 20.f, TEXT("None"));
	}

	FCPP_MyStruct strVar2 = { 3, false, 3.0f };

	strVar = strVar2;

	int32 ResultVar4 = strVar.Var1;
	FString StrResultVar4 = FString::Printf(TEXT("%d"), ResultVar4);
	UKismetSystemLibrary::PrintString(this, StrResultVar4, true, true, FColor::Blue, 20.f, TEXT("None"));

	if (strVar.Var2 == true)
	{
		float ResultVar5 = strVar.Var3;
		FString StrResultVar5 = FString::Printf(TEXT("%f"), ResultVar5);
		UKismetSystemLibrary::PrintString(this, StrResultVar5, true, true, FColor::Magenta, 20.f, TEXT("None"));
	}
}