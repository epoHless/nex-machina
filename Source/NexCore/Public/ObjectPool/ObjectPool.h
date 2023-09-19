// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PooledObject.h"
#include "Components/ActorComponent.h"
#include "ObjectPool.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class NEXCORE_API UObjectPool : public UActorComponent
{
	GENERATED_BODY()

public:
	UObjectPool();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Object Pool")
	TSubclassOf<class APooledObject> PooledObjectSubclass;

	UFUNCTION(BlueprintCallable, Category = "Object Pool")
	virtual APooledObject* SpawnPooledObject();
	
	UFUNCTION()
	void OnPooledObjectDespawn(APooledObject* PooledObject);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectDespawned(APooledObject* PooledObject);
	
protected:
	
	virtual void BeginPlay() override;
	
	void SetupPooledActor(APooledObject* PoolableActor);

	TArray<APooledObject*> ObjectPool;
	TArray<int> SpawnedPoolIndexes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Object Pool")
	int PoolSize = 20;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Object Pool")
	float PooledObjectLifeTime = 0.0f;
	
	UFUNCTION(BlueprintCallable, Category = "Object Pool")
	void InstantiatePoolableActors();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Object Pool")
	bool SpawnOnStart = true;
};
