// Fill out your copyright notice in the Description page of Project Settings.

#include "TOWBuffManager.h"


UTOWBuffManager::BuffFunc UTOWBuffManager::GetRunBuffFunc(UINT8 key)
{
	return nullptr;
}
UTOWBuffManager::BuffFunc UTOWBuffManager::GetRemoveBuffFunc(UINT8 key)
{
	return nullptr;
}

UTOWBuffManager* UTOWBuffManager::GetBuffManager()
{

	static UTOWBuffManager* instance = NewObject<UTOWBuffManager>();
	return instance;
}

