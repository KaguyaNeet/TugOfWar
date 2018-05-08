// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWBuff.h"
#include "TOWBaseUnit.h"
#include "TOWBuffManager.h"

void UTOWBuff::InitBuff(EBuffType buffType_, UINT8 buffKey, UINT8 buffValue_, UINT32 buffLifeTime_)
{
	buffType = buffType_;
	buffLifeTime = buffLifeTime_;
	buffValue = buffValue_;
	//RunBuffFunc = 
}

bool UTOWBuff::RunBuff(ATOWBaseUnit* buffOwner)
{
	buffLifeTime--;
	if (RunBuffFunc)
	{
		if (EBuffType::EOnce == buffType)
		{
			if (!isDo)
			{
				isDo = true;
				RunBuffFunc(buffValue, buffOwner);
			}
		}
		else
		{
			RunBuffFunc(buffValue, buffOwner);
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
	RemoveBuffFunc(buffValue, buffOwner);
}
