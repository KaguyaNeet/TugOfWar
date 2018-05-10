// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

	void ProduceTick();
	virtual void Produce(){}

	void Upgrade();
	virtual void Update(){}

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

	UINT16 upgradeCost = 0;
	UINT8 upgradeTime = 0;
	
private:
	
};
