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

//コンストラクタ
ACPP_BallPlayer::ACPP_BallPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponentを追加し、RootComponentに設定する
	//変数名 = CreateDefaultSubobject<追加するコンポーネント>(TEXT("表示したい名前"));
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Sphere;

	// StaticMeshをLoadしてStaticMeshComponentのStaticMeshに設定する
	//ポインタ型の読み込む型 変数名 = LoadObject<読み込む型>(nullptr, TEXT("読み込む物のパス"));
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));

	// StaticMeshをStaticMeshComponentに設定する
	//Sphere->と書けばSphereのコンポーネントにアクセスできる！
	//変数名->SetStaticMesh(セットするメッシュの変数);
	Sphere->SetStaticMesh(Mesh);

	// MaterialをStaticMeshに設定する
	//ポインタ型の読み込む型 変数名 = LoadObject<読み込む型>(nullptr, TEXT("読み込む物のパス"));
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));

	// MaterialをStaticMeshComponentに設定する
	//変数名->SetMaterial(複数のマテリアルを設定できる為、何番目か？を指定する, セットするマテリアルの変数);
	Sphere->SetMaterial(0, Material);

	// Simulate Physicsを有効にする
	//変数名->SetSimulatePhysics(trueなら有効、falseなら無効);
	Sphere->SetSimulatePhysics(true);

	// CollisionPresetを「PhysicsActor」に変更する
	Sphere->SetCollisionProfileName(TEXT("PhysicsActor"));

	//Hit Eventを有効にする
	Sphere->BodyInstance.bNotifyRigidBodyCollision = true;

	// SpringArmを追加する
	//変数名 = CreateDefaultSubobject<追加するコンポーネント>(TEXT("表示したい名前"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	//変数名->SetupAttachment(親オブジェクトにしたいオブジェクトが格納された変数);//指定した親オブジェクトの子オブジェクトにする
	SpringArm->SetupAttachment(RootComponent);

	// 角度を変更する FRotator(Pitch(Y), Yaw(Z), Roll(X))
	//SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));

	// Spring Armの長さを調整する
	SpringArm->TargetArmLength = 450.0f;

	//PawnのControllerRotationを使用する
	SpringArm->bUsePawnControlRotation = true;

	// SpringArmからの角度を継承しない
	//SpringArm->bInheritPitch = false;
	//SpringArm->bInheritYaw = false;
	//SpringArm->bInheritRoll = false;

	// CameraのLagを有効にする
	SpringArm->bEnableCameraLag = true;

	// Cameraを追加する
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm);

	//MotionBlurをオフにする
	Camera->PostProcessSettings.MotionBlurAmount = 0.0f;

	//Arrowを追加する
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	Arrow->SetupAttachment(Camera);

	//Sphereの頭上に移動するようにLocationを設定する
	Arrow->SetRelativeLocation(FVector(400.0f, 0.0f, 130.0f));

	//Arrowを表示されるようにする
	Arrow->bHiddenInGame = false;

	//Input Mappint Context「IM_Controls」を読み込む
	DefaultMappingContext = LoadObject<UInputMappingContext>(nullptr, TEXT("/Game/RollingBall/Input/IM_Controls"));

	//Input Action「IA_Control」を読み込む
	ControlAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Control"));

	//Input Action「IA_Look」を読み込む
	LookAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Look"));

	//Input Action「IA_Jump」を読み込む（④UnrealEngineで作成したキーを指定したインプットのシステムをロードしてアクション変数に入れる）
	JumpAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Jump"));

	//Input Action「IA_Boost」を読み込む
	BoostAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Boost"));
}

// Called when the game starts or when spawned
void ACPP_BallPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	//Input Mapping Contextを追加
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
		// ControlBallとIA_ControlのTriggeredをBindする
		EnhancedInputComponent->BindAction(ControlAction, ETriggerEvent::Triggered, this, &ACPP_BallPlayer::ControlBall);
	
		//LookとIA_LookのTriggeredをBindする
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPP_BallPlayer::Look);
	
		//JumpとIA_JumpのTriggeredをBindする（⑤インプットのコンポーネントにキー指定の変数と関数を入れる）
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACPP_BallPlayer::Jump);
	
		//BoostとIA_BoostのTriggeredをBindする
		EnhancedInputComponent->BindAction(BoostAction, ETriggerEvent::Triggered, this, &ACPP_BallPlayer::Boost);
	}
}

void ACPP_BallPlayer::ControlBall(const FInputActionValue& Value)
{
	//inputのValueはVector2Dに変換できる
	const FVector2D V = Value.Get<FVector2D>();

	//Vectorを計算する
	FVector ForceVector = FVector(V.Y, V.X, 0.0f) * Speed;

	//Arrowの進行方向のVectorの計算する
	FVector ArrowForceVector = Arrow->GetComponentToWorld().TransformVectorNoScale(ForceVector);

	//Sphereに力を加える
	Sphere->AddForce(ArrowForceVector, TEXT("NONE"), true);
}

void ACPP_BallPlayer::Look(const FInputActionValue& Value)
{
	//inputのValueはVector2Dに変換できる
	const FVector2D V = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		//add yaw and pitch input to controller
		AddControllerYawInput(V.X);
		AddControllerPitchInput(V.Y);

		//Pawnが持っているControlの角度を取得する
		FRotator ControlRotate = GetControlRotation();

		//controllerのPitchの角度を制限する
		double LimitPitchAngle = FMath::ClampAngle(ControlRotate.Pitch, -40.0f, -10.0f);

		//PlayerControllerの角度を設定する
		UGameplayStatics::GetPlayerController(this, 0)->SetControlRotation(FRotator(LimitPitchAngle, ControlRotate.Yaw, 0.0f));
	}
}

//（②関数の中身を作成する）
void ACPP_BallPlayer::Jump(const FInputActionValue& Value)
{
	//inputのValueはboolに変換できる
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
	//inputのValueはboolに変換できる
	if (const bool V = Value.Get<bool>())
	{
		//Arrowが向いている前方方向のVector情報を取得する
		FVector ForwardVector = Arrow->GetForwardVector().GetSafeNormal(0.0001f);

		//Torqueとして与えるVectorを作成する
		FVector TorqueVector = FVector(ForwardVector.Y * Torque * -1.0f, ForwardVector.X * Torque, 0.0f);

		//Torqueを与えて加速する
		Sphere->AddTorqueInRadians(TorqueVector, TEXT("None"), true);
	}
}