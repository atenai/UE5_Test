#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPConstructor.generated.h"

UCLASS()
class CPP_BP_API ACPPConstructor : public AActor
{
	GENERATED_BODY()
	
public:	
	//コンストラクタ
	ACPPConstructor();

	//デストラクタ
	~ACPPConstructor();

protected:
	virtual void BeginPlay() override;

	//Actorクラスの終了処理はEndPlayで実装する(Destroy の明示的な呼出し・レベル移行 (シームレスな移動またはマップのロード)で呼ばれる)
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Scene Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

private:

	// HP
	int hp = 0;
};
