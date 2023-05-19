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

	// �ÓI�����o�ϐ�
	static int staticPoint;

	// �ʏ�̃����o�ϐ�
	int normalPoint;

};
