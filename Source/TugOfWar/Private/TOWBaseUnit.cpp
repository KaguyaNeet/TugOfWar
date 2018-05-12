// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWBaseUnit.h"
#include "TOWBuff.h"
#include "TOWUnitManager.h"

// Sets default values
ATOWBaseUnit::ATOWBaseUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATOWBaseUnit::BeginPlay()
{
	Super::BeginPlay();
	
	if (ATOWUnitManager* unitManager = ATOWUnitManager::GetUnitManager(this))
	{
		ROLE_Authority == Role ? unitManager->AddUnit(this) : false ;
	}
}

// Called every frame
void ATOWBaseUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATOWBaseUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UINT16 ATOWBaseUnit::ApplyDamage(ATOWBaseUnit* damageCauser, UINT16 damageValue, UINT16 damagePenetration, ETOWDamageType damageType)
{
	UINT16 actualDamage = 0;
	if (ETOWDamageType::ETrueDamage == damageType)
	{
		actualDamage = damageValue;
	}
	else
	{
		UINT8 originalDefense = ETOWDamageType::EPhysicalDamage == damageType ? baseAttribute.physicalDefense : baseAttribute.magicDefense;
		UINT8 actualDefense = originalDefense * (1 - static_cast<float>(damagePenetration) / MAX_DEFENSE);
		actualDamage = damageValue * (1 - static_cast<float>(actualDefense) / MAX_DEFENSE);
	}

	if (baseAttribute.currentLifeValue <= actualDamage)
	{
		baseAttribute.currentLifeValue -= baseAttribute.currentLifeValue;
		Death(damageCauser);
	}
	else
	{
		baseAttribute.currentLifeValue -= actualDamage;
	}
	return actualDamage;
}

void ATOWBaseUnit::Death(ATOWBaseUnit* deathCauser)
{
	if (ATOWUnitManager* unitManager = ATOWUnitManager::GetUnitManager(this))
	{
		unitManager->RemoveUnit(this);
	}
}

void ATOWBaseUnit::RunBuff()
{
	buffList.Remove(nullptr);
	for (auto it : buffList)
	{
		if (!it->RunBuff(this))
		{
			it->RemoveBuff(this);
			it = nullptr;
		}
	}
}

void ATOWBaseUnit::AddBuff(class UTOWBuff* buff)
{
	buffList.Add(buff);
}

