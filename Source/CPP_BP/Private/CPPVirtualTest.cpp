

#include "CPPVirtualTest.h"
#include "CPPParentVirtual.h"
#include "CPPChildVirtual.h"
#include "CPPParentRedefinition.h"
#include "CPPChildRedefinition.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPVirtualTest::ACPPVirtualTest()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPVirtualTest::BeginPlay()
{
	Super::BeginPlay();
	
	// CPPChildRedefinition�𐶐�����
	ACPPParentRedefinition* redefinitionActor = GetWorld()->SpawnActor<ACPPChildRedefinition>(ACPPChildRedefinition::StaticClass());
	// SetPoint���Ăяo��
	redefinitionActor->SetPoint(100);
	// GetPoint�̒l���o�͂���
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Redefinition Point : %d"), redefinitionActor->GetPoint()), true, true, FColor::Cyan, 10.f, TEXT("None"));

	// CPPChildVirtual�𐶐�����
	ACPPParentVirtual* virautalActor = GetWorld()->SpawnActor<ACPPChildVirtual>(ACPPChildVirtual::StaticClass());
	// SetPoint���Ăяo��
	virautalActor->SetPoint(100);
	// GetPoint�̒l���o�͂���
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Virtual Point : %d"), virautalActor->GetPoint()), true, true, FColor::Red, 10.f, TEXT("None"));
}

void ACPPVirtualTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

