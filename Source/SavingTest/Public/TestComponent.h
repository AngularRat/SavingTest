#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"

#include "FL.h"
#include "DataObject.h"
#include "DataStruct.h"

#include "TestComponent.generated.h"


UCLASS()
class SAVINGTEST_API UTestComponent : public UStaticMeshComponent {
	GENERATED_BODY()

public:
	UTestComponent(const FObjectInitializer& ObjectInitializer);

	void Serialize(FArchive& Ar);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "TestComponent", Meta = (DisplayName = "DataObject"))
	UDataObject* DataObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TestComponent", Meta = (DisplayName = "DataStruct"))
	FDataStruct DataStruct;
};
