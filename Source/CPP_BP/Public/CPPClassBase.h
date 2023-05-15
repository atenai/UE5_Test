#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPClassBase.generated.h"

UCLASS()
class CPP_BP_API ACPPClassBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPClassBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Scene Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	// 親クラスのメンバ関数
	//ブループリントでノードとして扱えるようになる
	UFUNCTION(BlueprintCallable, Category=CPP_And_Blueprint)
	void CallParentFunc();

	// 親クラスのデータメンバ
	//基底クラスのデータメンバ[VarParentNum]のDefault値を変更したり、Set関数が呼び出せるようになります。
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Default)
	int VarParentNum = 10;
};
