// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TOWUnitManager.generated.h"

UCLASS()
class TUGOFWAR_API ATOWUnitManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATOWUnitManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddUnit(class ATOWBaseUnit*);
	void RemoveUnit(class ATOWBaseUnit*);

	static ATOWUnitManager* GetUnitManager(AActor* caller);

	
private:
	float buffTickCounter = 0;

	TArray<class ATOWBaseUnit*> unitList;
};
