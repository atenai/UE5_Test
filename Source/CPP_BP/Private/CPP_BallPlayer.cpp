// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_BallPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

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

	// SpringArmを追加する
	//変数名 = CreateDefaultSubobject<追加するコンポーネント>(TEXT("表示したい名前"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	//変数名->SetupAttachment(親オブジェクトにしたいオブジェクトが格納された変数);//指定した親オブジェクトの子オブジェクトにする
	SpringArm->SetupAttachment(RootComponent);

	// 角度を変更する FRotator(Pitch(Y), Yaw(Z), Roll(X))
	SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));

	// Spring Armの長さを調整する
	SpringArm->TargetArmLength = 450.0f;

	// SpringArmからの角度を継承しない
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	// CameraのLagを有効にする
	SpringArm->bEnableCameraLag = true;

	// Cameraを追加する
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

