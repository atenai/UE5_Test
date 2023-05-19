#include "CPPStaticTest.h"
#include "CPPStatic.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPStaticTest::ACPPStaticTest()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Satic•Ï”‚ð‰Šú‰»‚·‚é
int ACPPStatic::staticPoint = 400;


void ACPPStaticTest::BeginPlay()
{
	Super::BeginPlay();	

	// CPPStatic‚ð¶¬‚·‚é
	ACPPStatic* staticActorA = GetWorld()->SpawnActor<ACPPStatic>(ACPPStatic::StaticClass());
	// ƒƒ“ƒo•Ï”‚ðÝ’è‚·‚é
	staticActorA->normalPoint = 100;

	// CPPStatic‚ð¶¬‚·‚é
	ACPPStatic* staticActorB = GetWorld()->SpawnActor<ACPPStatic>(ACPPStatic::StaticClass());
	// ƒƒ“ƒo•Ï”‚ðÝ’è‚·‚é
	staticActorB->normalPoint = 200;

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("staticActorA staticPoint : %d, normalPoint : %d"), ACPPStatic::staticPoint, staticActorA->normalPoint), true, true, FColor::Cyan, 10.f, TEXT("None"));

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("staticActorB staticPoint : %d, normalPoint : %d"), staticActorB->staticPoint, staticActorB->normalPoint), true, true, FColor::Red, 10.f, TEXT("None"));
}

void ACPPStaticTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

