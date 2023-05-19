#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPParentVirtual.generated.h"

UCLASS()
class CPP_BP_API ACPPParentVirtual : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPParentVirtual();

protected:
	virtual void BeginPlay() override;

	int point;

public:	
	virtual void Tick(float DeltaTime) override;

	// Point‚ÌSetter‚ÆGetter
	virtual void SetPoint(int myPoint);
	int GetPoint();
};
