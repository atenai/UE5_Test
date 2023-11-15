// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerProjectile.h"
#include "UObject/ConstructorHelpers.h"

ACPP_PlayerProjectile::ACPP_PlayerProjectile() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("/Game/SM_PlayerProjectile.SM_PlayerProjectile"));

	if (StaticMeshComponent != nullptr && ProjectileMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(ProjectileMesh.Object);
	}
}

void ACPP_PlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//‰æ–Ê‰¡‚Ö”ò‚ñ‚Å‚¢‚­‚æ‚¤‚É‚·‚é
	MoveProjectile(FVector(0.0f, 400.0f, 0.0f), DeltaTime);
}