// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWBuildingBase.h"



void ATOWBuildingBase::ProduceTick()
{
	remainProduceTime--;
	if (0 == remainProduceTime)
	{
		remainProduceTime = maxProduceTime;
		Produce();
	}
}
