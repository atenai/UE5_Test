// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPComponent::ACPPComponent()
{
	PrimaryActorTick.bCanEverTick = true;

	// SceneComponentを作成する
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;

	// StaticMeshComponentを作成する
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// StaticMeshComponentをRootComponentにAttachする
	StaticMesh->SetupAttachment(RootComponent);//(Componentの変数名)->SetupAttachment( (Attachしたい親となるComponentの変数名)　);

	// ArrowComponentを作成する
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	// ArrowComponentの位置を設定する
	Arrow->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));

	// ArrowComponentをStaticMeshComponentにAttachする
	Arrow->SetupAttachment(StaticMesh);

	// PointLightComponentを作成する
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));

	// PointLightComponentの位置を設定する
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));

	// PointLightComponentをStaticMeshComponentにAttachする
	PointLight->SetupAttachment(StaticMesh);
}

void ACPPComponent::BeginPlay()
{
	Super::BeginPlay();

	// 変数を作成する
	FString Message = "C++ Hello World!";

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(
		this
		, Message
		, true
		, true
		, TextColor// Textのカラー情報に変数TextColorを設定
		, Duration
		, TEXT("None"));
}

void ACPPComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

