#include "ObjectPool/ObjectPool.h"

UObjectPool::UObjectPool()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UObjectPool::BeginPlay()
{
	Super::BeginPlay();
	InstantiatePoolableActors();
}

void UObjectPool::InstantiatePoolableActors()
{
	if (PooledObjectSubclass != nullptr)
	{
		UWorld* const World = GetWorld();

		if (World != nullptr)
		{
			for (int i = 0; i < PoolSize; i++)
			{
				APooledObject* PoolableActor = World->SpawnActor<APooledObject>(PooledObjectSubclass, FVector::ZeroVector, FRotator::ZeroRotator);

				if (PoolableActor != nullptr)
				{
					PoolableActor->SetActive(false);
					PoolableActor->SetPoolIndex(i);
					PoolableActor->OnPooledObjectDespawn.AddDynamic(this, &UObjectPool::OnPooledObjectDespawn);
					ObjectPool.Add(PoolableActor);
				}
			}
		}
	}
}

void UObjectPool::SetupPooledActor(APooledObject* PoolableActor)
{
	PoolableActor->TeleportTo(FVector(0,0,0), FRotator(0,0,0));
	PoolableActor->SetLifeSpan(PooledObjectLifeTime);
	PoolableActor->SetActive(true);

	PoolableActor->OnObjectRequest(GetOwner()->GetActorForwardVector());
	
	SpawnedPoolIndexes.Add(PoolableActor->GetPoolIndex());
}

APooledObject* UObjectPool::SpawnPooledObject()
{
	for (APooledObject* PoolableActor : ObjectPool)
	{
		if(PoolableActor != nullptr && !PoolableActor->IsActive())
		{
			SetupPooledActor(PoolableActor);
			return PoolableActor;
		}
	}

	if (SpawnedPoolIndexes.Num() > 0)
	{
		const int PooledObjectIndex = SpawnedPoolIndexes[0];
		SpawnedPoolIndexes.Remove(PooledObjectIndex);
		APooledObject* PoolableActor = ObjectPool[PooledObjectIndex];

		if (PoolableActor != nullptr)
		{
			PoolableActor->SetActive(false);			
			SetupPooledActor(PoolableActor);
			
			return PoolableActor;
		}
	}
	
	return nullptr;
}

void UObjectPool::OnPooledObjectDespawn(APooledObject* PooledObject)
{
	OnObjectDespawned(PooledObject);
	SpawnedPoolIndexes.Remove(PooledObject->GetPoolIndex());
}