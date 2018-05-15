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
			it->UnitTick();
		}
	}
}

void ATOWUnitManager::AddUnit(ATOWBaseUnit* unit)
{
	if (unit)
	{
		unitList.Add(unit);
		ETOWCamp::ERed == unit->baseAttribute.unitCamp ? redUnitList.Add(unit) : blueUnitList.Add(unit);
	}
}

void ATOWUnitManager::RemoveUnit(ATOWBaseUnit* unit)
{
	if (unit)
	{
		unitList.Remove(unit);
		ETOWCamp::ERed == unit->baseAttribute.unitCamp ? redUnitList.Remove(unit) : blueUnitList.Remove(unit);
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
		return caller->GetWorld()->SpawnActor<ATOWUnitManager>(FVector(0.f, 0.f, 0.f), FRotator(0.f, 0.f, 0.f));
	}
}

float ATOWUnitManager::Distance(AActor* a, AActor* b)
{
	return FVector::Distance(a->GetActorLocation(), a->GetActorLocation());
}

ATOWBaseUnit* ATOWUnitManager::GetNearestUnit(class ATOWBaseUnit* caller, const TArray<ATOWBaseUnit*>& list)
{
	float tempNearest = FLT_MAX;
	ATOWBaseUnit* tempNearestUnit = nullptr;
	for (auto it : list)
	{
		if (it != caller)
		{
			float temp = Distance(it, caller);
			temp < tempNearest ? tempNearest = temp, tempNearestUnit = it: false;
		}
	}
	return tempNearestUnit;
}

TArray<ATOWBaseUnit*> ATOWUnitManager::GetInRangeUnitsNotIncludeSelf(ATOWBaseUnit* caller, float range, const TArray<ATOWBaseUnit*>& list)
{
	TArray<ATOWBaseUnit*> tempArray;
	for (auto it : list)
	{
		if (it != caller)
		{
			float temp = Distance(it, caller);
			temp <= range ? tempArray.Add(it) : false;
		}
	}
	return tempArray;
}

ATOWBaseUnit* ATOWUnitManager::GetNearestFriend(ATOWBaseUnit* caller)
{
	return GetNearestUnit(caller, ETOWCamp::ERed == caller->baseAttribute.unitCamp ? redUnitList : blueUnitList);
}

ATOWBaseUnit* ATOWUnitManager::GetNearestEnemy(ATOWBaseUnit* caller)
{
	return GetNearestUnit(caller, ETOWCamp::ERed == caller->baseAttribute.unitCamp ? blueUnitList : redUnitList);
}

TArray<ATOWBaseUnit*> ATOWUnitManager::GetInRangeFriendsNotIncludeSelf(ATOWBaseUnit* caller, float range)
{
	return GetInRangeUnitsNotIncludeSelf(caller, range, ETOWCamp::ERed == caller->baseAttribute.unitCamp ? redUnitList : blueUnitList);
}

TArray<ATOWBaseUnit*> ATOWUnitManager::GetInRangeEnemies(ATOWBaseUnit* caller, float range)
{
	return GetInRangeUnitsNotIncludeSelf(caller, range, ETOWCamp::ERed == caller->baseAttribute.unitCamp ? blueUnitList : redUnitList);
}

TArray<ATOWBaseUnit*> ATOWUnitManager::GetInRangeUnitsNotIncludeSelf(ATOWBaseUnit* caller, float range)
{
	return GetInRangeUnitsNotIncludeSelf(caller, range, unitList);
}
