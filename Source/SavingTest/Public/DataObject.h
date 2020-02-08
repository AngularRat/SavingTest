#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "FL.h"

#include "DataObject.generated.h"


UCLASS(BlueprintType, EditInlineNew)
class SAVINGTEST_API UDataObject : public UObject {
	GENERATED_BODY()

public:
	UDataObject(const FObjectInitializer& ObjectInitializer);

	void Serialize(FArchive& Ar);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataObject")
	int32 Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataObject")
	int X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataObject")
	int Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataObject")
	int Z;

	UFUNCTION(BlueprintCallable, Category = "DataObject")
	void Initialize(int32 pId, int32 pX, int32 pY, int32 pZ);
};
