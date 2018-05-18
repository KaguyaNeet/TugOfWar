// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TOWBuffManager.generated.h"

/**
 * 
 */
UCLASS()
class TUGOFWAR_API UTOWBuffManager : public UObject
{
	GENERATED_BODY()
	
public:
	using BuffFunc = void(*)(UINT8 buffValue, class ATOWBaseUnit* buffOwner);

	BuffFunc GetRunBuffFunc(UINT8 key);
	BuffFunc GetRemoveBuffFunc(UINT8 key);

private:
};
