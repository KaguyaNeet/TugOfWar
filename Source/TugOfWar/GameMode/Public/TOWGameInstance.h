// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TOWGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TUGOFWAR_API UTOWGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UTOWGameInstance();

	class UTOWBuffManager* GetBuffManager() const;
	class UTOWCardManager* GetCardManager() const;

	void AddController(class ATOWPlayerController* playerController);

private:

	class UTOWBuffManager* buffManager;
	class UTOWCardManager* cardManager;

	class ATOWPlayerController* redPlayerController = nullptr;
	class ATOWPlayerController* bluePlayerController = nullptr;
	
};
