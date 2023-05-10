// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPConstructionScript.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPConstructionScript::ACPPConstructionScript()
{
	PrimaryActorTick.bCanEverTick = true;

	// SceneComponent���쐬����
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponent��RootComponent�ɐݒ肷��
	RootComponent = DefaultSceneRoot;

	// StaticMeshComponent���쐬����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// StaticMeshComponent��RootComponent��Attach����
	StaticMesh->SetupAttachment(RootComponent);

	// ArrowComponent���쐬����
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	// ArrowComponent�̈ʒu��ݒ肷��
	Arrow->SetRelativeLocation(FVector(30.0f, 0.0f, 0.0f));

	// ArrowComponent��StaticMeshComponent��Attach����
	Arrow->SetupAttachment(StaticMesh);

	// PointLightComponent���쐬����
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));

	// PointLightComponent�̈ʒu��ݒ肷��
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));

	// PointLightComponent��StaticMeshComponent��Attach����
	PointLight->SetupAttachment(StaticMesh);
}

void ACPPConstructionScript::BeginPlay()
{
	Super::BeginPlay();

	// �ϐ����쐬����
	FString Message = "CPPConstructionScript";

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(
		this
		, Message
		, true
		, true
		, TextColor// Text�̃J���[���ɕϐ�TextColor��ݒ�
		, Duration
		, TEXT("None"));
}

void ACPPConstructionScript::OnConstruction(const FTransform& Transform)
{
	//�w�b�_�[�ō쐬�����ϐ���K�p����
	// PointLight�̕\���E��\����ݒ�
	PointLight->SetVisibility(bIsVisible);

	//�w�b�_�[�ō쐬�����ϐ���K�p����
	// PointLight�̋�����ݒ�
	PointLight->SetIntensity(Intensity);

	//�w�b�_�[�ō쐬�����ϐ���K�p����
	// PointLight��LightColor��ݒ�
	PointLight->SetLightColor(LightColor);
}

void ACPPConstructionScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

