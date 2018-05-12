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

	class ATOWBaseUnit* GetNearestFriend(class ATOWBaseUnit* caller);
	class ATOWBaseUnit* GetNearestEnemy(class ATOWBaseUnit* caller);
	TArray<class ATOWBaseUnit*> GetInRangeFriendsNotIncludeSelf(class ATOWBaseUnit* caller, float range);
	TArray<class ATOWBaseUnit*> GetInRangeEnemies(class ATOWBaseUnit* caller, float range);
	TArray<class ATOWBaseUnit*> GetInRangeUnitsNotIncludeSelf(class ATOWBaseUnit* caller, float range);
	
private:
	float buffTickCounter = 0;

	UPROPERTY()
		TArray<class ATOWBaseUnit*> unitList;
	UPROPERTY()
		TArray<class ATOWBaseUnit*> redUnitList;
	UPROPERTY()
		TArray<class ATOWBaseUnit*> blueUnitList;

private:

	/*
	 * Get the nearest unit of caller.
	 * @param caller. caller's ptr.
	 * @param list. find unit in this list.
	 * @param ATOWBaseUnit*. return the found unit, can be nullptr.
	 **/
	class ATOWBaseUnit* GetNearestUnit(class ATOWBaseUnit* caller, const TArray<class ATOWBaseUnit*>& list);

	/*
	* Get the units in caller's range, not include caller self.
	* @param caller. caller's ptr.
	* @param range. find in this range.
	* @param list. find unit in this list.
	* @param TArray<ATOWBaseUnit*>. return the found units, can be null array.
	**/
	TArray<class ATOWBaseUnit*> GetInRangeUnitsNotIncludeSelf(class ATOWBaseUnit* caller, float range, const TArray<class ATOWBaseUnit*>& list);

	/*
	 * Get two actors distance.
	 **/
	float Distance(AActor* a, AActor* b);
};
