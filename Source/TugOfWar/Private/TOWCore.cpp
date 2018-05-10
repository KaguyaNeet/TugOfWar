// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWCore.h"
#include "TOWPlayerController.h"

#include "Public/UObject/ConstructorHelpers.h"

ATOWCore::ATOWCore()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> coreInfoDataTable(TEXT(""));

	if (coreInfoDataTable.Succeeded())
	{
		coreInfoTable = coreInfoDataTable.Object;
		coreInfoNames = coreInfoTable->GetRowNames();
	}
}

void ATOWCore::BeginPlay()
{
	Super::BeginPlay();

	//Core building initialize.
	maxLevel = coreInfoNames.Num() - 1;
	ATOWCore::Update();
}

void ATOWCore::Produce()
{
	if (owner)
	{
		owner->money += baseOutput;
	}
}

void ATOWCore::Update()
{
	buildingLevel++;
	FCoreInfo currentInfo = *coreInfoTable->FindRow<FCoreInfo>(coreInfoNames[buildingLevel], TEXT(""));
}

