// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWUnitManager.h"
#include "TOWBaseUnit.h"
#include "Character/TOWBuildingBase.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

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
			if (ATOWBuildingBase* building = Cast<ATOWBuildingBase>(it))
			{
				building->ProduceTick();
			}
		}
	}
}

void ATOWUnitManager::AddUnit(ATOWBaseUnit* unit)
{
	if (unit)
	{
		unitList.Add(unit);
	}
}

void ATOWUnitManager::RemoveUnit(ATOWBaseUnit* unit)
{
	if (unit)
	{
		unitList.Remove(unit);
	}
}

ATOWUnitManager* ATOWUnitManager::GetUnitManager(AActor* caller)
{
	TArray<AActor*> outManager;
	UGameplayStatics::GetAllActorsOfClass(caller, ATOWUnitManager::StaticClass(), outManager);
	if (outManager.Num() > 0 && outManager[0])
	{
		return Cast<ATOWUnitManager>(outManager[0]);
	}
	else
	{
		UE_LOG(LogExit , Error, TEXT("Can not find ATOWUnitManager, you should put a ATOWUnitManager to the level."));
		UGameplayStatics::GetPlayerController(caller, 0)->ConsoleCommand("quit");
		return nullptr;
	}
}

