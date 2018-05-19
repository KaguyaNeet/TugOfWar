// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWBuildingBase.h"
#include "TOWPlayerController.h"

#include "Kismet/GameplayStatics.h"

void ATOWBuildingBase::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> outPlayerControllers;
	UGameplayStatics::GetAllActorsOfClass(this, ATOWPlayerController::StaticClass(), outPlayerControllers);
	for (auto it : outPlayerControllers)
	{
		ATOWPlayerController* playerController = Cast<ATOWPlayerController>(it);
		if (playerController->playerCamp == baseAttribute.unitCamp)
		{
			owner = playerController;
		}
	}
}

void ATOWBuildingBase::UnitTick()
{
	Super::UnitTick();

	remainProduceTime--;
	if (0 == remainProduceTime)
	{
		remainProduceTime = maxProduceTime;
		Produce();
	}
}

void ATOWBuildingBase::Upgrade()
{
	if (buildingLevel < maxLevel)
	{
		owner->CostMoney(upgradeCost) ? Update() : false;
	}
}