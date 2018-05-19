// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWPlayerController.h"
#include "TOWGameInstance.h"

#include "Kismet/GameplayStatics.h"

void ATOWPlayerController::BeginPlay()
{
	if(UTOWGameInstance* gameInstance = Cast<UTOWGameInstance>(UGameplayStatics::GetGameInstance(this)))
	{
		gameInstance->AddController(this);
	}
}

bool ATOWPlayerController::CostMoney(UINT16 value)
{
	if(value <= money)
	{
		money -= value;
		return true;
	}
	return false;
}