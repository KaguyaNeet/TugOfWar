// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWCard.h"
#include "TOWCardManager.h"
#include "TOWGameInstance.h"

#include "Kismet/GameplayStatics.h"


void UTOWCard::InitCard(UINT8 cardKey)
{
	if (UTOWGameInstance* gameInstance = Cast<UTOWGameInstance>(UGameplayStatics::GetGameInstance(this)))
	{
		gameInstance->GetCardManager()->InitCard(this, cardKey);
	}
}

void UTOWCard::Use(class ATOWBaseUnit* unit)
{
	if (UTOWGameInstance* gameInstance = Cast<UTOWGameInstance>(UGameplayStatics::GetGameInstance(this)))
	{
		switch (cardInfo.cardType)
		{
		case ECardType::EAura:
			gameInstance->GetCardManager()->GetAuraFunc(cardID);

		}
	}

}

void UTOWCard::Remove(class ATOWBaseUnit* unit)
{

}
