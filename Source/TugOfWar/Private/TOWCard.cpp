// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWCard.h"
#include "TOWCardManager.h"


void UTOWCard::InitCard(UINT8 cardKey)
{
	UTOWCardManager::GetCardManager()->InitCard(this, cardKey);
}

void UTOWCard::Use(class ATOWBaseUnit* unit)
{
	switch (cardInfo.cardType)
	{
	case ECardType::EAura:UTOWCardManager::GetCardManager()->GetAuraFunc(cardID);

	}
}

void UTOWCard::Remove(class ATOWBaseUnit* unit)
{

}
