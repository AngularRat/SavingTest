
#include "SaveActor.h"


ASaveActor::ASaveActor()
{
 	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = SceneRoot;

	UE_LOG(LogTemp, Error, TEXT("%s Constructor (Line %s)"), *CPP_CLASS, *CPP_LINE);
}

void ASaveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASaveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UTestComponent* ASaveActor::CreateTestComponent(int32 id, int32 x, int32 y, int32 z) {
	UTestComponent* component = NewObject<UTestComponent>(this);
	AddInstanceComponent(component);

	UDataObject* dataObject = NewObject<UDataObject>();
	dataObject->Initialize(id, x, y, z);
	component->DataObject = dataObject;

	component->DataStruct = FDataStruct();
	component->DataStruct.Id = id;
	component->DataStruct.X = x;
	component->DataStruct.Y = y;
	component->DataStruct.Z = z;

	component->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	component->RegisterComponent();

	component->SetStaticMesh(TestMesh);
	component->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	component->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	component->SetCollisionProfileName(TEXT("UI"));

	GeneratedComponents.Add(component);

	return component;
}

void ASaveActor::ClearComponents() {
	for (int32 i = 0; i < GeneratedComponents.Num(); i++) {
		UStaticMeshComponent* usmc = GeneratedComponents[i];

		if (IsValid(usmc)) {
			if (!(usmc->IsPendingKillOrUnreachable())) {
				usmc->DestroyComponent();
			}
		}
	}

	GeneratedComponents.Empty();
}

