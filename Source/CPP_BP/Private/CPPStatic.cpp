#include "CPPStatic.h"

ACPPStatic::ACPPStatic()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPStatic::BeginPlay()
{
	Super::BeginPlay();	
}

void ACPPStatic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

