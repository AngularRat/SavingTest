#include "DataObject.h"

UDataObject::UDataObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	UE_LOG(LogTemp, Error, TEXT("%s Constructor (Line %s)"), *CPP_CLASS, *CPP_LINE);
}

void UDataObject::Serialize(FArchive& Ar) {
	Super::Serialize(Ar);

	if (Ar.IsSaving()) {
		UE_LOG(LogTemp, Error, TEXT("%s Serialize Saving (Line %s) (Id: %d X: %d Y: %d Z: %d)"), *CPP_CLASS, *CPP_LINE, Id, X, Y, Z);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s Serialize ?Loading? (Line %s) (Id: %d X: %d Y: %d Z: %d)"), *CPP_CLASS, *CPP_LINE, Id, X, Y, Z);
	}
}

void UDataObject::Initialize(int32 pId, int32 pX, int32 pY, int32 pZ)
{
	Id = pId;
	X = pX;
	Y = pY;
	Z = pZ;
}
