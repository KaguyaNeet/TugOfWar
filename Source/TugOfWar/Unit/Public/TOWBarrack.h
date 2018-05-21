// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"

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

USTRUCT()
struct FBarrackTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		UINT8 barrackLevel = 0;
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		ETOWBarrackType barrackType = ETOWBarrackType::EArcher;
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		UINT16 upgradeCost = 0;
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		UINT8 maxProduceTime = 0;
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
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
		class UArrowComponent* spawnArrow;
	UPROPERTY(EditAnywhere)
		ETOWBarrackType barrackType = ETOWBarrackType::EKnight;
	UPROPERTY(EditAnywhere)
		UDataTable* barrackDataTable = nullptr;

private:
	FUnitBaseAttribute unitAttribute;

	TMap<UINT8, FName> keyMap;
};
