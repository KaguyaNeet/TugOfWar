// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TOWBuildingBase.h"
#include "TOWBarrack.generated.h"

UENUM(BlueprintType)
enum class ETOWBarrackType : uint8
{
	EWizard UMETA(DisplayName = "Wizard"),
	EGiant UMETA(DisplayName = "Giant"),
	EArcher UMETA(DisplayName = "Archer"),
	EKnight UMETA(DisplayName = "Knight"),
};

/**
 * 
 */
UCLASS()
class TUGOFWAR_API ATOWBarrack : public ATOWBuildingBase
{
	GENERATED_BODY()
	
public:
	ATOWBarrack();
	virtual void Produce() override;
	virtual void Update() override;

public:
	UPROPERTY(EditAnywhere)
		class UArrowComponent* spawnArrow;
	UPROPERTY(EditAnywhere)
		ETOWBarrackType barrackType = ETOWBarrackType::EKnight;

private:
	FUnitBaseAttribute unitAttribute;
};
