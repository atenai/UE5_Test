#include "CPPStaticTest.h"
#include "CPPStatic.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPStaticTest::ACPPStaticTest()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Satic変数を初期化する
int ACPPStatic::staticPoint = 400;


void ACPPStaticTest::BeginPlay()
{
	Super::BeginPlay();	

	// CPPStaticを生成する
	ACPPStatic* staticActorA = GetWorld()->SpawnActor<ACPPStatic>(ACPPStatic::StaticClass());
	// メンバ変数を設定する
	staticActorA->normalPoint = 100;

	// CPPStaticを生成する
	ACPPStatic* staticActorB = GetWorld()->SpawnActor<ACPPStatic>(ACPPStatic::StaticClass());
	// メンバ変数を設定する
	staticActorB->normalPoint = 200;

	// 静的メンバ関数を呼び出す
	ACPPStatic::SetPoint(500);
	staticActorA->SetPoint(600);

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("staticActorA staticPoint : %d, normalPoint : %d"), ACPPStatic::staticPoint, staticActorA->normalPoint), true, true, FColor::Cyan, 10.f, TEXT("None"));

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("staticActorB staticPoint : %d, normalPoint : %d"), staticActorB->staticPoint, staticActorB->normalPoint), true, true, FColor::Red, 10.f, TEXT("None"));
}

void ACPPStaticTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

