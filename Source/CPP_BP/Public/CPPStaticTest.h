#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPStaticTest.generated.h"

UCLASS()
class CPP_BP_API ACPPStaticTest : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPStaticTest();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
