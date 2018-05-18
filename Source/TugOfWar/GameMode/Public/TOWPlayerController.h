// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TOWBaseUnit.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TOWPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TUGOFWAR_API ATOWPlayerController : public APlayerController
{
	GENERATED_BODY()


public:

	virtual void BeginPlay() override;


public:

	ETOWCamp playerCamp = ETOWCamp::ENeutral;

	UINT32 money = 0;
	
	
};
