// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CppExampleStruct.h"
#include "CppExampleEnum.h"//こいつが問題

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

	UFUNCTION(BlueprintCallable, Category = "UE C++ book")//BlueprintCallableをつけた関数は必ずcppに関数の処理内容を書く！！（じゃないとコンパイルエラーになる）
	float MyActorFunc(const float Input);

private:

	FString test = "Kashiwabara";

	const FLinearColor TextColor = FColor::Magenta;

};
