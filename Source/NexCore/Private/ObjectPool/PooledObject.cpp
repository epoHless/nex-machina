﻿#include "ObjectPool/PooledObject.h"

APooledObject::APooledObject()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APooledObject::Deactivate()
{
	OnObjectDeactivated();
	
	SetActive(false);
	GetWorldTimerManager().ClearAllTimersForObject(this);
	OnPooledObjectDespawn.Broadcast(this);
}

void APooledObject::SetActive(bool IsActive)
{
	Active = IsActive;
	SetActorHiddenInGame(!IsActive);
	GetWorldTimerManager().SetTimer(LifeSpanTimer, this, &APooledObject::Deactivate, LifeSpan, false);
}

void APooledObject::SetLifeSpan(float LifeTime)
{
	LifeSpan = LifeTime;
}

void APooledObject::SetPoolIndex(int Index)
{
	PoolIndex = Index;
}

bool APooledObject::IsActive() const
{
	return Active;
}

int APooledObject::GetPoolIndex() const
{
	return PoolIndex;
}
