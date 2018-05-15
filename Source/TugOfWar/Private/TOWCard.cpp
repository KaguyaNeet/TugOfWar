// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWCard.h"
#include "TOWCardManager.h"

#include "Kismet/GameplayStatics.h"


void UTOWCard::InitCard(UINT8 cardKey)
{
	UTOWCardManager::InitCard(this, cardKey);
}

void UTOWCard::Use(class ATOWBaseUnit* unit)
{
	UTOWCardManager::GetCardFunc(cardInfo.cardType, unit, cardID);
}

void UTOWCard::Remove(class ATOWBaseUnit* unit)
{

}
