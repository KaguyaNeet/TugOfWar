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
	
	void ProduceTick();
	virtual void Produce(){}

public:

	UPROPERTY(EditAnywhere)
		UINT8 maxProduceTime = 0;
	UPROPERTY(EditAnywhere)
		UINT8 remainProduceTime = 5;
	
	
};
