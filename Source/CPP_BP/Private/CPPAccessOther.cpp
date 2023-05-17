// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAccessOther.h"
#include "CPPAccessParent.h"//アクセスしたいアクターのヘッダーをインクルード
#include "Kismet/GameplayStatics.h"//ほかのアクターを探すために必要なヘッダーをインクルード

// Sets default values
ACPPAccessOther::ACPPAccessOther()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPAccessOther::BeginPlay()
{
	Super::BeginPlay();
	
	// ViewportにあるACPPAccessParentを探す
	AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), ACPPAccessParent::StaticClass());

	// 取得したAActorからACPPAccessParentに変換する 
	ACPPAccessParent* CPPAccessParent = Cast<ACPPAccessParent>(FoundActor);

	// CPPAccessParentのデータメンバ(Public)を変更する
	CPPAccessParent->VarPublicNum = 1000;

	// CPPAccessParentのデータメンバ(Protected)を変更する
	//CPPAccessParent->VarProtectedNum = 2000;

	// CPPAccessParentのデータメンバ(Private)を変更する
	//CPPAccessParent->VarPrivateNum = 3000;

	// CPPAccessParentのメンバ関数(Public)を呼び出す
	CPPAccessParent->CallPublicFunc();

	// CPPAccessParentのメンバ関数(Protected)を呼び出す
	//CPPAccessParent->CallProtectedFunc();

	// CPPAccessParentのメンバ関数(Private)を呼び出す
	//CPPAccessParent->CallPrivateFunc();
}

// Called every frame
void ACPPAccessOther::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

