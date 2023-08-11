﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PooledObject.h"
#include "Components/ActorComponent.h"
#include "ObjectPool.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class NEXCORE_API UObjectPool : public UActorComponent
{
	GENERATED_BODY()

public:
	UObjectPool();
	void InstantiatePoolableActors();

	UFUNCTION(BlueprintCallable, Category = "Object Pool")
	APooledObject* SpawnPooledObject();

	UPROPERTY(EditAnywhere, Category = "Object Pool")
	TSubclassOf<class APooledObject> PooledObjectSubclass;

	UPROPERTY(EditAnywhere, Category = "Object Pool")
	int PoolSize = 20;

	UPROPERTY(EditAnywhere, Category = "Object Pool")
	float PooledObjectLifeTime = 0.0f;

	UFUNCTION()
	void OnPooledObjectDespawn(APooledObject* PooledObject);
	
protected:
	virtual void BeginPlay() override;
	void SetupPooledActor(APooledObject* PoolableActor);

	TArray<APooledObject*> ObjectPool;
	TArray<int> SpawnedPoolIndexes;

};
