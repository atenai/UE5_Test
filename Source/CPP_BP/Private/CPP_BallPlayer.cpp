// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BallPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

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

	// CollisionPreset���uPhysicsActor�v�ɕύX����
	Sphere->SetCollisionProfileName(TEXT("PhysicsActor"));

	//Hit Event��L���ɂ���
	Sphere->BodyInstance.bNotifyRigidBodyCollision = true;

	// SpringArm��ǉ�����
	//�ϐ��� = CreateDefaultSubobject<�ǉ�����R���|�[�l���g>(TEXT("�\�����������O"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	//�ϐ���->SetupAttachment(�e�I�u�W�F�N�g�ɂ������I�u�W�F�N�g���i�[���ꂽ�ϐ�);//�w�肵���e�I�u�W�F�N�g�̎q�I�u�W�F�N�g�ɂ���
	SpringArm->SetupAttachment(RootComponent);

	// �p�x��ύX���� FRotator(Pitch(Y), Yaw(Z), Roll(X))
	//SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));

	// Spring Arm�̒����𒲐�����
	SpringArm->TargetArmLength = 450.0f;

	//Pawn��ControllerRotation���g�p����
	SpringArm->bUsePawnControlRotation = true;

	// SpringArm����̊p�x���p�����Ȃ�
	//SpringArm->bInheritPitch = false;
	//SpringArm->bInheritYaw = false;
	//SpringArm->bInheritRoll = false;

	// Camera��Lag��L���ɂ���
	SpringArm->bEnableCameraLag = true;

	// Camera��ǉ�����
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);

	//MotionBlur���I�t�ɂ���
	Camera->PostProcessSettings.MotionBlurAmount = 0.0f;

	//Arrow��ǉ�����
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	Arrow->SetupAttachment(Camera);

	//Sphere�̓���Ɉړ�����悤��Location��ݒ肷��
	Arrow->SetRelativeLocation(FVector(400.0f, 0.0f, 130.0f));

	//Arrow��\�������悤�ɂ���
	Arrow->bHiddenInGame = false;

	//Input Mappint Context�uIM_Controls�v��ǂݍ���
	DefaultMappingContext = LoadObject<UInputMappingContext>(nullptr, TEXT("/Game/RollingBall/Input/IM_Controls"));

	//Input Action�uIA_Control�v��ǂݍ���
	ControlAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Control"));

	//Input Action�uIA_Look�v��ǂݍ���
	LookAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Look"));

	//Input Action�uIA_Jump�v��ǂݍ��ށi�CUnrealEngine�ō쐬�����L�[���w�肵���C���v�b�g�̃V�X�e�������[�h���ăA�N�V�����ϐ��ɓ����j
	JumpAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Jump"));

	//Input Action�uIA_Boost�v��ǂݍ���
	BoostAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Boost"));
}

// Called when the game starts or when spawned
void ACPP_BallPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	//Input Mapping Context��ǉ�
	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
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
	
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// ControlBall��IA_Control��Triggered��Bind����
		EnhancedInputComponent->BindAction(ControlAction, ETriggerEvent::Triggered, this, &ACPP_BallPlayer::ControlBall);
	
		//Look��IA_Look��Triggered��Bind����
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPP_BallPlayer::Look);
	
		//Jump��IA_Jump��Triggered��Bind����i�D�C���v�b�g�̃R���|�[�l���g�ɃL�[�w��̕ϐ��Ɗ֐�������j
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACPP_BallPlayer::Jump);
	
		//Boost��IA_Boost��Triggered��Bind����
		EnhancedInputComponent->BindAction(BoostAction, ETriggerEvent::Triggered, this, &ACPP_BallPlayer::Boost);
	}
}

void ACPP_BallPlayer::ControlBall(const FInputActionValue& Value)
{
	//input��Value��Vector2D�ɕϊ��ł���
	const FVector2D V = Value.Get<FVector2D>();

	//Vector���v�Z����
	FVector ForceVector = FVector(V.Y, V.X, 0.0f) * Speed;

	//Arrow�̐i�s������Vector�̌v�Z����
	FVector ArrowForceVector = Arrow->GetComponentToWorld().TransformVectorNoScale(ForceVector);

	//Sphere�ɗ͂�������
	Sphere->AddForce(ArrowForceVector, TEXT("NONE"), true);
}

void ACPP_BallPlayer::Look(const FInputActionValue& Value)
{
	//input��Value��Vector2D�ɕϊ��ł���
	const FVector2D V = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		//add yaw and pitch input to controller
		AddControllerYawInput(V.X);
		AddControllerPitchInput(V.Y);

		//Pawn�������Ă���Control�̊p�x���擾����
		FRotator ControlRotate = GetControlRotation();

		//controller��Pitch�̊p�x�𐧌�����
		double LimitPitchAngle = FMath::ClampAngle(ControlRotate.Pitch, -40.0f, -10.0f);

		//PlayerController�̊p�x��ݒ肷��
		UGameplayStatics::GetPlayerController(this, 0)->SetControlRotation(FRotator(LimitPitchAngle, ControlRotate.Yaw, 0.0f));
	}
}

//�i�A�֐��̒��g���쐬����j
void ACPP_BallPlayer::Jump(const FInputActionValue& Value)
{
	//input��Value��bool�ɕϊ��ł���
	if (const bool V = Value.Get<bool>() && CanJump)
	{
		Sphere->AddImpulse(FVector(0.0f, 0.0f, JumpImpluse), TEXT("None"), true);
		CanJump = false;
	}
}

void ACPP_BallPlayer::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	CanJump = true;
}

void ACPP_BallPlayer::Boost(const FInputActionValue& Value)
{
	//input��Value��bool�ɕϊ��ł���
	if (const bool V = Value.Get<bool>())
	{
		//Arrow�������Ă���O��������Vector�����擾����
		FVector ForwardVector = Arrow->GetForwardVector().GetSafeNormal(0.0001f);

		//Torque�Ƃ��ė^����Vector���쐬����
		FVector TorqueVector = FVector(ForwardVector.Y * Torque * -1.0f, ForwardVector.X * Torque, 0.0f);

		//Torque��^���ĉ�������
		Sphere->AddTorqueInRadians(TorqueVector, TEXT("None"), true);
	}
}