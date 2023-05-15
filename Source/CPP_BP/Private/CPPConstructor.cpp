#include "CPPConstructor.h"
#include "Kismet/KismetSystemLibrary.h"

//�R���X�g���N�^
ACPPConstructor::ACPPConstructor()
{
	PrimaryActorTick.bCanEverTick = true;

	// �����o�ϐ�������������
	hp = 100;

	// SceneComponent��RootComponent�ɐݒ肷��B
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponent��RootComponent�ɐݒ肷��
	RootComponent = DefaultSceneRoot;

	// StaticMeshComponent���쐬����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/CPP_BP/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// StaticMeshComponent��RootComponent��Attach����
	StaticMesh->SetupAttachment(RootComponent);
}

ACPPConstructor::~ACPPConstructor()
{
	//�f�X�g���N�^��PrintString
	//UKismetSystemLibrary::PrintString(this, TEXT("Destructor Class destroyed"), true, true, FColor::Cyan, 2.f, TEXT("None"));//�f�X�g���N�^���Ɣj������ČĂ΂�Ȃ�
}

void ACPPConstructor::BeginPlay()
{
	Super::BeginPlay();
	
	// Constructor�ŏ����������ϐ���PrintString�ŏo�͂���
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%d"), hp), true, true, FColor::Cyan, 2.f, TEXT("None"));
}

void ACPPConstructor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// EndPlay��PrintString
	UKismetSystemLibrary::PrintString(this, TEXT("EndPlay Class destroyed"), true, true, FColor::Cyan, 2.f);//�j�����ꂽ�ۂɂ�΂��
}

void ACPPConstructor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

