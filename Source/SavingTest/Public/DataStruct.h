#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "FL.h"

#include "DataStruct.generated.h"


USTRUCT(BlueprintType)
struct FDataStruct {
	GENERATED_BODY()

public:
	FDataStruct();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataStruct")
	int32 Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataStruct")
	int X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataStruct")
	int Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataStruct")
	int Z;
};
