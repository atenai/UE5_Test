#pragma once

#include "CppExampleStruct.generated.h"

USTRUCT(BlueprintType)
struct FCppExampleStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UE C++ book")
	float Value;

	UPROPERTY(BlueprintReadWrite, EditAnywhere , Category = "UE C++ book")
	int32 Index;
};
