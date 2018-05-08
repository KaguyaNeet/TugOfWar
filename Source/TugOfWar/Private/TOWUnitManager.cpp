// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWUnitManager.h"
#include "TOWBaseUnit.h"

// Sets default values
ATOWUnitManager::ATOWUnitManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATOWUnitManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATOWUnitManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Run all unit's buff system per second.
	buffTickCounter += DeltaTime;
	if (buffTickCounter >= 1.f)
	{
		buffTickCounter = 0;
		for (auto it : unitList)
		{
			it->RunBuff();
		}
	}
}

