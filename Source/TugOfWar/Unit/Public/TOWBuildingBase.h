// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TOWCardManager.h"

#include "CoreMinimal.h"
#include "TOWBaseUnit.h"
#include "TOWBuildingBase.generated.h"

/**
 * 
 */
UCLASS()
class TUGOFWAR_API ATOWBuildingBase : public ATOWBaseUnit
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void UnitTick() override;
	virtual void Produce(){}

	void Upgrade();
	virtual void Update(){}

	virtual bool AddCard(class UTOWCard* card) { return false; }

public:
	class ATOWPlayerController* owner = nullptr;

	UPROPERTY(EditAnywhere)
		UINT8 maxProduceTime = 0;
	UPROPERTY(EditAnywhere)
		UINT8 remainProduceTime = 5;
	UPROPERTY(EditAnywhere)
		UINT8 buildingLevel = 0;
	UPROPERTY(EditAnywhere)
		UINT8 maxLevel = 0;

	UPROPERTY()
		TArray<class UTOWCard*> cards;

	UINT16 upgradeCost = 0;
	UINT8 upgradeTime = 0;

	TArray<UTOWCardManager::BuildingCardFunc> buildingFuncs;

	UPROPERTY(EditAnywhere)
		class UDataTable* dataTable;

private:


	
};
