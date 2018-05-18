// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWGameInstance.h"
#include "TOWCardManager.h"
#include "TOWBuffManager.h"
#include "TOWBaseUnit.h"
#include "TOWPlayerController.h"

UTOWGameInstance::UTOWGameInstance()
{
	buffManager = NewObject<UTOWBuffManager>();
	cardManager = NewObject<UTOWCardManager>();
}

UTOWBuffManager* UTOWGameInstance::GetBuffManager() const
{
	return buffManager;
}

UTOWCardManager* UTOWGameInstance::GetCardManager() const
{
	return cardManager;
}

void UTOWGameInstance::AddController(ATOWPlayerController* playerController)
{
	if(nullptr == redPlayerController)
	{
		redPlayerController = playerController;
		playerController->playerCamp = ETOWCamp::ERed;
		return;
	}
	if(nullptr == bluePlayerController)
	{
		bluePlayerController = playerController;
		playerController->playerCamp = ETOWCamp::EBlue;
		return;
	}
	check(0);
}