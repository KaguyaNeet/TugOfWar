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
	virtual void UnitTick() override;

	virtual void Init(FUnitBaseAttribute initInfo);

//Write public value here
public:

	TArray<UTOWCardManager::AuroCardFunc> auraFuncs;
	TArray<UTOWCardManager::TrenchCardFunc> trenchFuncs;
	TArray<UTOWCardManager::DeathWordsCardFunc> deathWordsFuncs;
	TArray<UTOWCardManager::UnitSpellCardFunc> unitSpellFuncs;
	TArray<UTOWCardManager::AttackEffectCardFunc> attackEffectFuncs;
	TArray<UTOWCardManager::ArmsCardFunc> armsFuncs;
	TArray<UTOWCardManager::ArmorCardFunc> armorFuncs;

private:
	void RunFuncs(TArray<void(*)(ATOWBaseUnit*)>&);
	void RunFuncs(TArray<void(*)(ATOWBaseUnit*, ATOWBaseUnit*)>&, ATOWBaseUnit*);

	virtual void Death(ATOWBaseUnit* deathCauser) override;
	
	
};
