// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"

#include "TOWCardManager.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TOWCard.generated.h"



USTRUCT()
struct FCardInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		FName cardName;
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		ECardType cardType;
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		FString cardDesc;
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		UINT16 cardCost;
};

USTRUCT()
struct FCardDataTableStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		UINT8 key;
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		FCardInfo cardInfo;
	UPROPERTY(EditAnywhere, Category = "CardDesc")
		UINT8 cardEnum;

};

/**
 * 
 */
UCLASS()
class TUGOFWAR_API UTOWCard : public UObject
{
	GENERATED_BODY()
	
public:

	void InitCard(UINT8 cardKey);

	void Use(class ATOWBaseUnit* unit);
	void Remove(class ATOWBaseUnit* unit);
	
public:

	FCardInfo cardInfo;
	UINT8 key;
	ECardName cardID;
	bool isOpen = true;
};
