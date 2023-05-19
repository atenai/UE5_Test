#include "CPPParentVirtual.h"

ACPPParentVirtual::ACPPParentVirtual()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPParentVirtual::BeginPlay()
{
	Super::BeginPlay();
}

void ACPPParentVirtual::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPPParentVirtual::SetPoint(int myPoint)
{
	point = myPoint;
}

int ACPPParentVirtual::GetPoint()
{
	return point;
}