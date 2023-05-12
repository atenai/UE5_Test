// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CppExampleStruct.h"
#include "CppExampleEnum.h"//���������

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestKashiwabara.generated.h"

UCLASS(BlueprintType)
class CPP_BP_API ATestKashiwabara : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestKashiwabara();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE C++ book")
	FCppExampleStruct MyStructProp;

	UPROPERTY(BlueprintReadWrite ,EditAnywhere, Category = "UE C++ book")
	ECppExampleEnum Type;

	UFUNCTION(BlueprintCallable, Category = "UE C++ book")//BlueprintCallable�������֐��͕K��cpp�Ɋ֐��̏������e�������I�I�i����Ȃ��ƃR���p�C���G���[�ɂȂ�j
	float MyActorFunc(const float Input);

private:

	FString test = "Kashiwabara";

	const FLinearColor TextColor = FColor::Magenta;

};
