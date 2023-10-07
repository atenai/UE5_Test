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

	// StaticMesh��Load����StaticMeshComponent��StaticMesh�ɐݒ肷��
	//�|�C���^�^�̓ǂݍ��ތ^ �ϐ��� = LoadObject<�ǂݍ��ތ^>(nullptr, TEXT("�ǂݍ��ޕ��̃p�X"));
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));

	// StaticMesh��StaticMeshComponent�ɐݒ肷��
	//Sphere->�Ə�����Sphere�̃R���|�[�l���g�ɃA�N�Z�X�ł���I
	//�ϐ���->SetStaticMesh(�Z�b�g���郁�b�V���̕ϐ�);
	Sphere->SetStaticMesh(Mesh);

	// Material��StaticMesh�ɐݒ肷��
	//�|�C���^�^�̓ǂݍ��ތ^ �ϐ��� = LoadObject<�ǂݍ��ތ^>(nullptr, TEXT("�ǂݍ��ޕ��̃p�X"));
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));

	// Material��StaticMeshComponent�ɐݒ肷��
	//�ϐ���->SetMaterial(�����̃}�e���A����ݒ�ł���ׁA���Ԗڂ��H���w�肷��, �Z�b�g����}�e���A���̕ϐ�);
	Sphere->SetMaterial(0, Material);

	// Simulate Physics��L���ɂ���
	//�ϐ���->SetSimulatePhysics(true�Ȃ�L���Afalse�Ȃ疳��);
	Sphere->SetSimulatePhysics(true);

	// SpringArm��ǉ�����
	//�ϐ��� = CreateDefaultSubobject<�ǉ�����R���|�[�l���g>(TEXT("�\�����������O"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	//�ϐ���->SetupAttachment(�e�I�u�W�F�N�g�ɂ������I�u�W�F�N�g���i�[���ꂽ�ϐ�);//�w�肵���e�I�u�W�F�N�g�̎q�I�u�W�F�N�g�ɂ���
	SpringArm->SetupAttachment(RootComponent);

	// �p�x��ύX���� FRotator(Pitch(Y), Yaw(Z), Roll(X))
	SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));

	// Spring Arm�̒����𒲐�����
	SpringArm->TargetArmLength = 450.0f;

	// SpringArm����̊p�x���p�����Ȃ�
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	// Camera��Lag��L���ɂ���
	SpringArm->bEnableCameraLag = true;

	// Camera��ǉ�����
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);
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

