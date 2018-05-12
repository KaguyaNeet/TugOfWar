// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWGameInstance.h"
#include "TOWCardManager.h"
#include "TOWBuffManager.h"

UTOWGameInstance::UTOWGameInstance()
{
	buffManager = NewObject<UTOWBuffManager>();
	cardManager = NewObject<UTOWCardManager>();
}

UTOWBuffManager* UTOWGameInstance::GetBuffManager()
{
	return buffManager;
}

UTOWCardManager* UTOWGameInstance::GetCardManager()
{
	return cardManager;
}