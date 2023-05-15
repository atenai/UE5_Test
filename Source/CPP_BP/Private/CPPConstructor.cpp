#include "CPPConstructor.h"
#include "Kismet/KismetSystemLibrary.h"

//コンストラクタ
ACPPConstructor::ACPPConstructor()
{
	PrimaryActorTick.bCanEverTick = true;

	// メンバ変数を初期化する
	hp = 100;

	// SceneComponentをRootComponentに設定する。
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;

	// StaticMeshComponentを作成する
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/CPP_BP/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// StaticMeshComponentをRootComponentにAttachする
	StaticMesh->SetupAttachment(RootComponent);
}

ACPPConstructor::~ACPPConstructor()
{
	//デストラクタでPrintString
	//UKismetSystemLibrary::PrintString(this, TEXT("Destructor Class destroyed"), true, true, FColor::Cyan, 2.f, TEXT("None"));//デストラクタだと破棄されて呼ばれない
}

void ACPPConstructor::BeginPlay()
{
	Super::BeginPlay();
	
	// Constructorで初期化した変数をPrintStringで出力する
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%d"), hp), true, true, FColor::Cyan, 2.f, TEXT("None"));
}

void ACPPConstructor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// EndPlayでPrintString
	UKismetSystemLibrary::PrintString(this, TEXT("EndPlay Class destroyed"), true, true, FColor::Cyan, 2.f);//破棄された際によばれる
}

void ACPPConstructor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

