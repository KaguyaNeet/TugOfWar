// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWBarrack.h"
#include "TOWCard.h"
#include "TOWPlayerController.h"
#include "TOWCharacter.h"
#include "Components/ArrowComponent.h"

ATOWBarrack::ATOWBarrack()
{
	spawnArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnArrow"));
}

void ATOWBarrack::BeginPlay()
{
	Super::BeginPlay();

	if (barrackDataTable)
	{
		TArray<FName> dataTableRowNames = barrackDataTable->GetRowNames();
		for(auto it : dataTableRowNames)
		{
			FBarrackTable* tempBarrackData = barrackDataTable->FindRow<FBarrackTable>(it, TEXT(""));
			if(tempBarrackData->barrackType == this->barrackType)
			{
				keyMap.Add(tempBarrackData->barrackLevel, it);
			}
		}
	}
}

void ATOWBarrack::Produce()
{
	cards.Remove(nullptr);

	UINT16 cost = 0;

	for(auto it : cards)
	{
		it->isOpen ? cost += it->cardInfo.cardCost : false;
	}

	ATOWCharacter* character = GetWorld()->SpawnActor<ATOWCharacter>(spawnArrow->GetComponentLocation(), spawnArrow->GetComponentRotation());
	character->Init(unitAttribute);

	if(owner->CostMoney(cost))
	{
		for(auto it : cards)
		{
			if(it->isOpen)
			{
				it->Use(character);
			}
		}
	}
}

void ATOWBarrack::Update()
{
	
}

