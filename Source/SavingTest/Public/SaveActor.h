// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "FL.h"
#include "TestComponent.h"
#include "DataObject.h"
#include "DataStruct.h"

#include "SaveActor.generated.h"

UCLASS()
class SAVINGTEST_API ASaveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASaveActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveActor", Meta = (DisplayName = "SceneRoot", ExposeOnSpawn = true))
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveActor", Meta = (DisplayName = "TestMesh", ExposeOnSpawn = true))
	UStaticMesh* TestMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UTestComponent*> GeneratedComponents;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "SaveActor")
	UTestComponent* CreateTestComponent(int32 id, int32 x, int32 y, int32 z);

	UFUNCTION(BlueprintCallable, Category = "SaveActor")
	void ClearComponents();
};
