// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TOWBaseUnit.h"

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TOWGameMode.generated.h"

/**
 * 
 */


UCLASS()
class TUGOFWAR_API ATOWGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	void GameFinish(ETOWCamp failedCamp);
	
	
};
