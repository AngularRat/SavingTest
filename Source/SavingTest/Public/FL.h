#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FL.generated.h"


#define CPP_LINE  (FString::FromInt(__LINE__))
#define CPP_CLASS (FString(__FUNCTION__))


UCLASS()
class SAVINGTEST_API UFL : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
	
};
