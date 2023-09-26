#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PooledObject.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPooledObjectDelegate, APooledObject*, PooledObject);

UCLASS()
class NEXCORE_API APooledObject : public AActor
{
	GENERATED_BODY()

public:
	APooledObject();

	UPROPERTY(BlueprintAssignable, Category = "Object Pool")
	FPooledObjectDelegate OnPooledObjectDespawn;

	UFUNCTION(BlueprintCallable, Category = "Pooled Object")
	virtual void Deactivate();

	void SetActive(bool IsActive);
	void SetLifeSpan(float LifeTime);
	void SetPoolIndex(int Index);

	UFUNCTION(BlueprintPure)
	bool IsActive() const;
	
	int GetPoolIndex() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "PooledObject")
	void OnObjectRequest(FVector Direction);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "PooledObject")
	void OnObjectDeactivated();

protected:

	bool Active;

	UPROPERTY(EditAnywhere, Category = "Pooled Object")
	float LifeSpan = 0.0f;
	
	int PoolIndex;

	FTimerHandle LifeSpanTimer;
};