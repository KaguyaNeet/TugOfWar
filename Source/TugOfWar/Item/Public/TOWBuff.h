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
	/*
	 * Initialize this buff.
	 * @param buffType_. this buff's type.
	 * @param buffKey. this buff's key, use to get buff function from UTOWBuffManager.
	 * @param buffValue. this buff's buff value, influence this buff's power.
	 * @param lifeTime. this buff's life time, reduced per RunBuff.
	 **/
	void InitBuff(EBuffType buffType_, UINT8 buffKey, UINT8 buffValue, UINT32 lifeTime);

	/*
	 * Will be called per second by these owner, and lifetime -1
	 * Call this buff's run function.
	 * If this buff's type is once, it will run only in the first.
	 * @param buffOwner. This buff's owner.only buff owner can own this buff's reference, if owner set this buff's ptr to nullptr it will be GC.
	 * @return bool. If this buff's lifetime == 0, return false, and this buff's owner can remove it.
	 **/
	bool RunBuff(class ATOWBaseUnit* buffOwner);

	/*
	 * Will be called if RunBuff return false by these owner.
	 * Call this buff's remove function.
	 * @param buffOwner. This buff's owner.
	 **/
	void RemoveBuff(class ATOWBaseUnit* buffOwner);

//Public value write here.
public:
	EBuffType buffType = EBuffType::EOnce;
	UINT32 buffLifeTime = 0;

//Private value write here.
private:
	//is this buff ran? only use if bufftype == once.
	bool isDo = false;
	//this buff's level, influence this buff's value.
	UINT8 buffValue = 0;

	using BuffFunc = void(*)(UINT8 buffValue, class ATOWBaseUnit* buffOwner);
	//RunBuff will call this function ptr.
	BuffFunc RunBuffFuncPtr = nullptr;
	//RemoveBuff will call this function ptr.
	BuffFunc RemoveBuffFuncPtr = nullptr;
};
