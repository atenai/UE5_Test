// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CppExampleStruct.h"
#include "CppExampleEnum.h"//‚±‚¢‚Â‚ª–â‘è

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestKashiwabara.generated.h"

//UCLASS(BlueprintType)
UCLASS()
class CPP_BP_API ATestKashiwabara : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestKashiwabara();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

		/*UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE C++ book")
	FCppExampleStruct MyStructProp;

	UPROPERTY(BlueprintReadWrite ,EditAnywhere, Category = "UE C++ book")
	ECppExamepleEnum Type;

	UFUNCTION(BlueprintCallable, Category = "UE C++ book")
	float MyActorFunc(const float Input);*/

private:

	FString test = "Kashiwabara";

	const FLinearColor TextColor = FColor::Magenta;

};
