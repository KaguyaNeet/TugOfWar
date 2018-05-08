// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TOWBuff.generated.h"

UENUM(BlueprintType)
enum class EBuffType : uint8
{
	ETick UMETA(DisplayName = "Tick"),
	EOnce UMETA(DisplayName = "Once"),
};

/**
 * 
 */
UCLASS()
class TUGOFWAR_API UTOWBuff : public UObject
{
	GENERATED_BODY()

public:
	void InitBuff(EBuffType buffType_, UINT8 buffKey, UINT8 buffValue, UINT32 lifeTime);

	bool RunBuff(class ATOWBaseUnit* buffOwner);

	void RemoveBuff(class ATOWBaseUnit* buffOwner);

public:
	EBuffType buffType = EBuffType::EOnce;
	UINT32 buffLifeTime = 0;

private:
	bool isDo = false;
	UINT8 buffValue = 0;

	using BuffFuncPtr = void(*)(UINT8 buffValue, class ATOWBaseUnit* buffOwner);
	BuffFuncPtr RunBuffFunc = nullptr;
	BuffFuncPtr RemoveBuffFunc = nullptr;
};
