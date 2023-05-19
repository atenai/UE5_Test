
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPVirtualTest.generated.h"

UCLASS()
class CPP_BP_API ACPPVirtualTest : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPVirtualTest();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
