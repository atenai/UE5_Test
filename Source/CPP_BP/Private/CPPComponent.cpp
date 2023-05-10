// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPComponent::ACPPComponent()
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
	StaticMesh->SetupAttachment(RootComponent);//(Component�̕ϐ���)->SetupAttachment( (Attach�������e�ƂȂ�Component�̕ϐ���)�@);

	// ArrowComponent���쐬����
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	// ArrowComponent�̈ʒu��ݒ肷��
	Arrow->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));

	// ArrowComponent��StaticMeshComponent��Attach����
	Arrow->SetupAttachment(StaticMesh);

	// PointLightComponent���쐬����
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));

	// PointLightComponent�̈ʒu��ݒ肷��
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));

	// PointLightComponent��StaticMeshComponent��Attach����
	PointLight->SetupAttachment(StaticMesh);
}

void ACPPComponent::BeginPlay()
{
	Super::BeginPlay();

	// �ϐ����쐬����
	FString Message = "C++ Hello World!";

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

void ACPPComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

