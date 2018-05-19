// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWCharacter.h"

void ATOWCharacter::Init(FUnitBaseAttribute initInfo)
{
	baseAttribute = initInfo;
}

void ATOWCharacter::UnitTick() 
{
	Super::UnitTick();

	RunFuncs(auraFuncs);
}

void ATOWCharacter::RunFuncs(TArray<void(*)(ATOWBaseUnit*)>& funcs)
{
	for (auto it : funcs)
	{
		it(this);
	}
}

void ATOWCharacter::RunFuncs(TArray<void(*)(ATOWBaseUnit*, ATOWBaseUnit*)>& funcs, ATOWBaseUnit* other)
{
	for (auto it : funcs)
	{
		it(this, other);
	}
}

void ATOWCharacter::Death(ATOWBaseUnit* deathCauser)
{
	Super::Death(deathCauser);

	RunFuncs(deathWordsFuncs, deathCauser);
}


