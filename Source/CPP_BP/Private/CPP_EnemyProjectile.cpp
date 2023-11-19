// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EnemyProjectile.h"
#include "UObject/ConstructorHelpers.h"
//#include "Engine.h"

ACPP_EnemyProjectile::ACPP_EnemyProjectile() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("/Game/SM_EnemyProjectile.SM_EnemyProjectile"));
	if (StaticMeshComponent != nullptr && ProjectileMesh.Succeeded())
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("EnemyTamaTrue"));
		StaticMeshComponent->SetStaticMesh(ProjectileMesh.Object);
	}
}

void ACPP_EnemyProjectile::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
	MoveProjectile(FVector(0.0f, -200.0f, 0.0f), Deltatime);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("EnemyTamaMoveTrue"));
}
