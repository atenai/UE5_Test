﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

ACPP_PlayerPawn::ACPP_PlayerPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//TestAddComponent(ObjectInitializer);
	StaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMesh"));
	if (StaticMeshComponent != nullptr)
	{
		RootComponent = StaticMeshComponent;
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlayerMeshObj(TEXT("/Game/SM_Player.SM_Player"));
	//初期のStaticMeshにセット
	if (ensure(PlayerMeshObj.Succeeded()))
	{
		StaticMeshComponent->SetStaticMesh(PlayerMeshObj.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//インプット用の初期化処理の関数を作成する①
//void InitializeDefaultPawnInputBindings()
//{
//	static bool bBindingsAdded = false;
//	if (!bBindingsAdded)
//	{
//		bBindingsAdded = true;
//		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_Turn", EKeys::MouseY, 1.0f));
//	}
//}

//インプット用の関数を作成する③
//void ACPP_PlayerPawn::AddControllerYawInput(float Val)
//{
//	Super::AddControllerYawInput(Val);
//
//	//マウスに合わせて移動させる
//	SetActorLocation(GetPlayerMoveDirection(Val));
//}

// Called to bind functionality to input
void ACPP_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//ここでインプット用の処理を初期化する関数を呼んでから↑で作成したインプット用の関数をバインドする④
	//InitializeDefaultPawnInputBindings();
	//PlayerInputComponent->BindAxis("DefaultPawn_Turn", this, &ACPP_PlayerPawn::AddControllerYawInput);
}

void ACPP_PlayerPawn::TestAddComponent(const FObjectInitializer& ObjectInitializer)
{
	// USceneComponent を RootComponent にする
	USceneComponent* NewRootSceneComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("NewRootComponent"));
	if (NewRootSceneComponent != nullptr)
	{
		RootComponent = NewRootSceneComponent;
	}

	// UStaticMeshComponent のアタッチ
	StaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMeshTest"));
	if (StaticMeshComponent != nullptr)
	{
		StaticMeshComponent->SetupAttachment(RootComponent);
	}
}

FVector ACPP_PlayerPawn::GetPlayerMoveDirection(float Direction) const
{
	return (FVector(10.0f,0.0f,0.0f) * Direction) + GetActorLocation();
}

void ACPP_PlayerPawn::MouseMovePitchInput(float Val)
{
	SetActorLocation(GetPlayerMoveDirection(Val));
}