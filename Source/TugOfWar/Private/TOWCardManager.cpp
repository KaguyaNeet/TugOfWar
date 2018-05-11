// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWCardManager.h"
#include "TOWCard.h"
#include "TOWBaseUnit.h"

#include "Public/UObject/ConstructorHelpers.h"

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

UTOWCardManager* UTOWCardManager::GetCardManager()
{
	static UTOWCardManager* instance = NewObject<UTOWCardManager>();
	return instance;
}


void UTOWCardManager::InitCard(UTOWCard* card, UINT8 cardKey)
{
	FName* cardName = keyMap.Find(cardKey);
	FCardDataTableStruct* cardStruct = cardDataTable->FindRow<FCardDataTableStruct>(*cardName, TEXT(""));
	card->cardInfo = cardStruct->cardInfo;
	card->key = cardKey;
	card->cardID = cardStruct->cardEnum;
}

UTOWCardManager::AuroCardFunc UTOWCardManager::GetAuraFunc(ECardName cardName)
{
	switch (cardName)
	{
	case ECardName::EAura:return [](ATOWBaseUnit* owner) {};
	default:return nullptr;
	}
}
