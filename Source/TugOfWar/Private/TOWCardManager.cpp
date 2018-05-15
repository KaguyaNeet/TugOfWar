// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWCardManager.h"
#include "TOWCard.h"
#include "TOWBaseUnit.h"
#include "Character/TOWCharacter.h"
#include "Character/TOWBuildingBase.h"
#include "TOWGameInstance.h"

#include "Public/UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

UTOWCardManager::UTOWCardManager()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> cardData(TEXT(""));
	if (cardData.Succeeded())
	{
		cardDataTable = cardData.Object;
		TArray<FName> names = cardDataTable->GetRowNames();
		for (auto it : names)
		{
			UINT8 key = (cardDataTable->FindRow<FCardDataTableStruct>(it, TEXT("")))->key;
			keyMap.Add(key, it);
		}
	}
}

void UTOWCardManager::InitCard(UTOWCard* card, UINT8 cardKey)
{
	if (UTOWGameInstance* gameInstance = Cast<UTOWGameInstance>(UGameplayStatics::GetGameInstance(card)))
	{
		UTOWCardManager* cardManager = gameInstance->GetCardManager();
		FName* cardName = cardManager->keyMap.Find(cardKey);
		FCardDataTableStruct* cardStruct = cardManager->cardDataTable->FindRow<FCardDataTableStruct>(*cardName, TEXT(""));
		card->cardInfo = cardStruct->cardInfo;
		card->key = cardKey;
		card->cardID = static_cast<ECardName>(cardStruct->cardEnum);
	}
}

void UTOWCardManager::GetCardFunc(ECardType cardType, class ATOWBaseUnit* unit, ECardName cardEnum)
{
	if (UTOWGameInstance* gameInstance = Cast<UTOWGameInstance>(UGameplayStatics::GetGameInstance(unit)))
	{
		UTOWCardManager* cardManager = gameInstance->GetCardManager();
		switch (cardType)
		{
		case ECardType::EAura:
			if (ATOWCharacter* character = Cast<ATOWCharacter>(unit)) 
				character->auraFuncs.Add(cardManager->GetAuraFunc(cardEnum));
			return;
		case ECardType::ETrench:
			if (ATOWCharacter* character = Cast<ATOWCharacter>(unit)) 
				character->trenchFuncs.Add(cardManager->GetTrenchCardFunc(cardEnum));
			return;
		case ECardType::EDeathWords:
			if (ATOWCharacter* character = Cast<ATOWCharacter>(unit)) 
				character->deathWordsFuncs.Add(cardManager->GetDeathWordsCardFunc(cardEnum));
			return;
		case ECardType::EUnitSpell:
			if (ATOWCharacter* character = Cast<ATOWCharacter>(unit)) 
				character->unitSpellFuncs.Add(cardManager->GetUnitSpellCardFunc(cardEnum));
			return;
		case ECardType::EAttackEffect:
			if (ATOWCharacter* character = Cast<ATOWCharacter>(unit)) 
				character->attackEffectFuncs.Add(cardManager->GetAttackEffectCardFunc(cardEnum));
			return;
		case ECardType::EArms:
			if (ATOWCharacter* character = Cast<ATOWCharacter>(unit)) 
				character->armsFuncs.Add(cardManager->GetArmsCardFunc(cardEnum));
			return;
		case ECardType::EArmor:
			if (ATOWCharacter* character = Cast<ATOWCharacter>(unit)) 
				character->armorFuncs.Add(cardManager->GetArmorCardFunc(cardEnum));
			return;
		case ECardType::EPlayer:
			return;
		case ECardType::EBuilding:
			if (ATOWBuildingBase* building = Cast<ATOWBuildingBase>(unit)) 
				building->buildingFuncs.Add(cardManager->GetBuildingCardFunc(cardEnum));
			return;

		}
	}
}

UTOWCardManager::AuroCardFunc UTOWCardManager::GetAuraFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::ETestAura:return [](ATOWBaseUnit* owner) {};
	default:return nullptr;
	}
}

UTOWCardManager::TrenchCardFunc UTOWCardManager::GetTrenchCardFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::ETestAura:return [](ATOWBaseUnit* owner) {};
	default:return nullptr;
	}
}
UTOWCardManager::DeathWordsCardFunc UTOWCardManager::GetDeathWordsCardFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::ETestAura:return [](ATOWBaseUnit* owner, ATOWBaseUnit* other) {};
	default:return nullptr;
	}
}
UTOWCardManager::UnitSpellCardFunc UTOWCardManager::GetUnitSpellCardFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::ETestAura:return [](ATOWBaseUnit* owner, ATOWBaseUnit* other) {};
	default:return nullptr;
	}
}
UTOWCardManager::AttackEffectCardFunc UTOWCardManager::GetAttackEffectCardFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::ETestAura:return [](ATOWBaseUnit* owner, ATOWBaseUnit* other) {};
	default:return nullptr;
	}
}
UTOWCardManager::ArmsCardFunc UTOWCardManager::GetArmsCardFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::ETestAura:return [](ATOWBaseUnit* owner, ATOWBaseUnit* other) {};
	default:return nullptr;
	}
}
UTOWCardManager::ArmorCardFunc UTOWCardManager::GetArmorCardFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::ETestAura:return [](ATOWBaseUnit* owner, ATOWBaseUnit* other) {};
	default:return nullptr;
	}
}
UTOWCardManager::PlayerCardFunc UTOWCardManager::GetPlayerCardFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::ETestAura:return [](ATOWBaseUnit* owner) {};
	default:return nullptr;
	}
}

UTOWCardManager::BuildingCardFunc UTOWCardManager::GetBuildingCardFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::ETestAura:return [](ATOWBaseUnit* owner) {};
	default:return nullptr;
	}
}

