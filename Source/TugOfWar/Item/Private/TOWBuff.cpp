// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWBuff.h"
#include "TOWBaseUnit.h"
#include "TOWBuffManager.h"
#include "TOWGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UTOWBuff::InitBuff(EBuffType buffType_, UINT8 buffKey, UINT8 buffValue_, UINT32 buffLifeTime_)
{
	buffType = buffType_;
	buffLifeTime = buffLifeTime_;
	buffValue = buffValue_;
	if (UTOWGameInstance* gameInstance = Cast<UTOWGameInstance>(UGameplayStatics::GetGameInstance(this)))
	{
		gameInstance->GetBuffManager()->GetRunBuffFunc(buffKey);
		gameInstance->GetBuffManager()->GetRemoveBuffFunc(buffKey);
	}
}

bool UTOWBuff::RunBuff(ATOWBaseUnit* buffOwner)
{
	buffLifeTime--;
	if (RunBuffFuncPtr)
	{
		if (EBuffType::EOnce == buffType)
		{
			if (!isDo)
			{
				isDo = true;
				RunBuffFuncPtr(buffValue, buffOwner);
			}
		}
		else
		{
			RunBuffFuncPtr(buffValue, buffOwner);
		}
	}

	if (0 == buffLifeTime)
	{
		return false;
	}
	return true;
}

void UTOWBuff::RemoveBuff(ATOWBaseUnit* buffOwner)
{
	RemoveBuffFuncPtr(buffValue, buffOwner);
}
