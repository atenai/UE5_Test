#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPStatic.generated.h"

UCLASS()
class CPP_BP_API ACPPStatic : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPStatic();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// staticメンバ関数
	static void SetPoint(int myPoint);

	// 静的メンバ変数
	static int staticPoint;

	// 通常のメンバ変数
	int normalPoint;

};
