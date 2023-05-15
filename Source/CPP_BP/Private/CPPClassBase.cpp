
#include "CPPClassBase.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPClassBase::ACPPClassBase()
{
	PrimaryActorTick.bCanEverTick = true;

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

void ACPPClassBase::BeginPlay()
{
	Super::BeginPlay();
	
	CallParentFunc();
}

void ACPPClassBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPClassBase::CallParentFunc()
{
	// Viewport�ɔz�u����Actor�̕\�������擾����
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintString��Actor�\����,�����o�֐�,�f�[�^�����o���o��
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallParentFunc %d"), *name, VarParentNum), true, true, FColor::Cyan, 10.f, TEXT("None"));
}