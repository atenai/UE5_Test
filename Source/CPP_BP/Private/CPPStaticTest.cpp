#include "CPPStaticTest.h"
#include "CPPStatic.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPStaticTest::ACPPStaticTest()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Satic�ϐ�������������
int ACPPStatic::staticPoint = 400;


void ACPPStaticTest::BeginPlay()
{
	Super::BeginPlay();	

	// CPPStatic�𐶐�����
	ACPPStatic* staticActorA = GetWorld()->SpawnActor<ACPPStatic>(ACPPStatic::StaticClass());
	// �����o�ϐ���ݒ肷��
	staticActorA->normalPoint = 100;

	// CPPStatic�𐶐�����
	ACPPStatic* staticActorB = GetWorld()->SpawnActor<ACPPStatic>(ACPPStatic::StaticClass());
	// �����o�ϐ���ݒ肷��
	staticActorB->normalPoint = 200;

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("staticActorA staticPoint : %d, normalPoint : %d"), ACPPStatic::staticPoint, staticActorA->normalPoint), true, true, FColor::Cyan, 10.f, TEXT("None"));

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("staticActorB staticPoint : %d, normalPoint : %d"), staticActorB->staticPoint, staticActorB->normalPoint), true, true, FColor::Red, 10.f, TEXT("None"));
}

void ACPPStaticTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

