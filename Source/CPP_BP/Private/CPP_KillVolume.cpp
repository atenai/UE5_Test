// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_KillVolume.h"
#include "Components/BoxComponent.h"
#include "CPP_InGameGameMode.h"
#include "Kismet/GameplayStatics.h"
//#include "Engine.h"

// Sets default values
ACPP_KillVolume::ACPP_KillVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SceneComponentを作成する
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;

	KillVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));

	// BoxComponentをRootComponentにAttachする
	KillVolume->SetupAttachment(RootComponent);

	// BoxComponentのOnComponentBegineOverlapに関数「OnBoxBeginOverlap」を関連づける
	KillVolume->OnComponentBeginOverlap.AddDynamic(this, &ACPP_KillVolume::OnBoxBeginOverlap);

	//スクリーンにメッセージを表示する
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("ACPP_KillVolume()"));
}

// Called when the game starts or when spawned
void ACPP_KillVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_KillVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_KillVolume::OnConstruction(const FTransform& Transform)
{
	// KillVolumeのBox Extentを変更する
	KillVolume->SetBoxExtent(BoxExtent);

	//スクリーンにメッセージを表示する
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("OnConstruction()"));
}

void ACPP_KillVolume::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//スクリーンにメッセージを表示する
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("ACPP_KillVolume::OnBoxBeginOverlap1"));

	// 接触したActorがBallPlayerか判定する
	if (ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(OtherActor))
	{
		//スクリーンにメッセージを表示する
		//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("ACPP_KillVolume::OnBoxBeginOverlap2"));

		// GameModeを取得して、InGameGameModeにCastする
		if (ACPP_InGameGameMode* GameMode = Cast<ACPP_InGameGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			//スクリーンにメッセージを表示する
			//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("ACPP_KillVolume::OnBoxBeginOverlap3"));

			// KillPlayerを呼び出してPlayerを破棄する
			GameMode->KillPlayer(Player);
		}
	}
}