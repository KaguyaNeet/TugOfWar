// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TOWCardManager.generated.h"

UENUM(BlueprintType)
enum class ECardName : uint8
{
	ETestAura UMETA(DisplayName = "AuraCard"),

};

UENUM(BlueprintType)
enum class ECardType : uint8
{
	EAura UMETA(DisplayName = "AuraCard"),
	ETrench UMETA(DisplayName = "TrenchCard"),
	EDeathWords UMETA(DisplayName = "DeathWordsCard"),
	EUnitSpell UMETA(DisplayName = "UnitSpellCard"),
	EAttackEffect UMETA(DisplayName = "AttackEffectCard"),
	EArms UMETA(DisplayName = "ArmsCard"),
	EArmor UMETA(DisplayName = "ArmorCard"),
	EBuilding UMETA(DisplayName = "BuildingCard"),
	EPlayer UMETA(DisplayName = "PlayerCard"),
	EOther UMETA(DisplayName = "OtherCard"),
};
/**
 * 
 */
UCLASS()
class TUGOFWAR_API UTOWCardManager : public UObject
{
	GENERATED_BODY()

public:
	using AuroCardFunc = void(*)(class ATOWBaseUnit*);
	using TrenchCardFunc = void(*)(class ATOWBaseUnit*);
	using DeathWordsCardFunc = void(*)(class ATOWBaseUnit*, class ATOWBaseUnit*);
	using UnitSpellCardFunc = void(*)(class ATOWBaseUnit*, class ATOWBaseUnit*);
	using AttackEffectCardFunc = void(*)(class ATOWBaseUnit*, class ATOWBaseUnit*);
	using ArmsCardFunc = void(*)(class ATOWBaseUnit*, class ATOWBaseUnit*);
	using ArmorCardFunc = void(*)(class ATOWBaseUnit*, class ATOWBaseUnit*);
	using PlayerCardFunc = void(*)(class ATOWBaseUnit*);
	using BuildingCardFunc = void(*)(class ATOWBaseUnit*);
	
public:
	UTOWCardManager();

	static void InitCard(class UTOWCard* card, UINT8 cardKey);

	static void GetCardFunc(ECardType cardType, class ATOWBaseUnit* unit, ECardName cardEnum);
	
	AuroCardFunc GetAuraFunc(ECardName cardName);
	TrenchCardFunc GetTrenchCardFunc(ECardName cardName);
	DeathWordsCardFunc GetDeathWordsCardFunc(ECardName cardName);
	UnitSpellCardFunc GetUnitSpellCardFunc(ECardName cardName);
	AttackEffectCardFunc GetAttackEffectCardFunc(ECardName cardName);
	ArmsCardFunc GetArmsCardFunc(ECardName cardName);
	ArmorCardFunc GetArmorCardFunc(ECardName cardName);
	PlayerCardFunc GetPlayerCardFunc(ECardName cardName);
	BuildingCardFunc GetBuildingCardFunc(ECardName cardName);
private:
	class UDataTable* cardDataTable;
	TMap<UINT8, FName> keyMap;
};
