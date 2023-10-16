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

	// SceneComponent���쐬����
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponent��RootComponent�ɐݒ肷��
	RootComponent = DefaultSceneRoot;

	KillVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));

	// BoxComponent��RootComponent��Attach����
	KillVolume->SetupAttachment(RootComponent);

	// BoxComponent��OnComponentBegineOverlap�Ɋ֐��uOnBoxBeginOverlap�v���֘A�Â���
	KillVolume->OnComponentBeginOverlap.AddDynamic(this, &ACPP_KillVolume::OnBoxBeginOverlap);

	//�X�N���[���Ƀ��b�Z�[�W��\������
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
	// KillVolume��Box Extent��ύX����
	KillVolume->SetBoxExtent(BoxExtent);

	//�X�N���[���Ƀ��b�Z�[�W��\������
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("OnConstruction()"));
}

void ACPP_KillVolume::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//�X�N���[���Ƀ��b�Z�[�W��\������
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("ACPP_KillVolume::OnBoxBeginOverlap1"));

	// �ڐG����Actor��BallPlayer�����肷��
	if (ACPP_BallPlayer* Player = Cast<ACPP_BallPlayer>(OtherActor))
	{
		//�X�N���[���Ƀ��b�Z�[�W��\������
		//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("ACPP_KillVolume::OnBoxBeginOverlap2"));

		// GameMode���擾���āAInGameGameMode��Cast����
		if (ACPP_InGameGameMode* GameMode = Cast<ACPP_InGameGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			//�X�N���[���Ƀ��b�Z�[�W��\������
			//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("ACPP_KillVolume::OnBoxBeginOverlap3"));

			// KillPlayer���Ăяo����Player��j������
			GameMode->KillPlayer(Player);
		}
	}
}