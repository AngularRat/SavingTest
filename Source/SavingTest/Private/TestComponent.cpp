#include "TestComponent.h"

UTestComponent::UTestComponent(const FObjectInitializer& ObjectInitializer) {
	UE_LOG(LogTemp, Error, TEXT("%s Constructor (Line %s)"), *CPP_CLASS, *CPP_LINE);
	ObjectInitializer.CreateDefaultSubobject<UDataObject>(this, TEXT("DataObject"));
}

void UTestComponent::Serialize(FArchive& Ar) {
	Super::Serialize(Ar);

	if (Ar.IsSaving()) {
		UE_LOG(LogTemp, Warning, TEXT("%s Saving (Line %s)"), *CPP_CLASS, *CPP_LINE);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s ?Loading? (Line %s)"), *CPP_CLASS, *CPP_LINE);
	}
}
