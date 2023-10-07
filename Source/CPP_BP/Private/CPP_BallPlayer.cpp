// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BallPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

//�R���X�g���N�^
ACPP_BallPlayer::ACPP_BallPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponent��ǉ����ARootComponent�ɐݒ肷��
	//�ϐ��� = CreateDefaultSubobject<�ǉ�����R���|�[�l���g>(TEXT("�\�����������O"));
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Sphere;

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	//�|�C���^�^�̓ǂݍ��ތ^ M�ϐ��� = LoadObject<�ǂݍ��ތ^>(nullptr, TEXT("�ǂݍ��ޕ��̃p�X"));
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	//Sphere->�Ə�����Sphere�̃R���|�[�l���g�ɃA�N�Z�X�ł���I
	Sphere->SetStaticMesh(Mesh);

	// Material��StaticMesh�ɐݒ肷��
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));

	// Material��StaticMeshComponent�ɐݒ肷��
	Sphere->SetMaterial(0, Material);

	// Simulate Physics��L���ɂ���
	Sphere->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ACPP_BallPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_BallPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_BallPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

