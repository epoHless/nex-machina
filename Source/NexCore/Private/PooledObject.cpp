// Fill out your copyright notice in the Description page of Project Settings.


#include "PooledObject.h"


// Sets default values
APooledObject::APooledObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APooledObject::Deactivate()
{
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

bool APooledObject::IsActive()
{
	return Active;
}

int APooledObject::GetPoolIndex()
{
	return PoolIndex;
}

