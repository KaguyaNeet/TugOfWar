// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TOWCard.h"

#include "CoreMinimal.h"
#include "TOWBaseUnit.h"
#include "TOWCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TUGOFWAR_API ATOWCharacter : public ATOWBaseUnit
{
	GENERATED_BODY()
	
public:
	TArray<UTOWCardManager::AuroCardFunc> auraFuncPtrs;
	
	
};
