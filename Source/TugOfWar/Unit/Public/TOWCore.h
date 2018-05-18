// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"

#include "CoreMinimal.h"
#include "TOWBuildingBase.h"
#include "TOWCore.generated.h"

USTRUCT()
struct FCoreInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "CoreInfo")
		UINT8 level = 1;
	UPROPERTY(EditAnywhere, Category = "CoreInfo")
		UINT16 upgradeCost = 0;
	UPROPERTY(EditAnywhere, Category = "CoreInfo")
		UINT16 baseOutput = 0;
	UPROPERTY(EditAnywhere, Category = "CoreInfo")
		UINT16 maxLifeValue = 0;
};

/**
 * 
 */
UCLASS()
class TUGOFWAR_API ATOWCore : public ATOWBuildingBase
{
	GENERATED_BODY()
	
public:

	ATOWCore();

	virtual void Produce() override;
	virtual void BeginPlay() override;
	virtual void Update() override;


	virtual void Death(ATOWBaseUnit* deathCauser) override;
private:

	
	UINT16 baseOutput = 0;

	class UDataTable* coreInfoTable = nullptr;
	TArray<FName> coreInfoNames;
 	
};
