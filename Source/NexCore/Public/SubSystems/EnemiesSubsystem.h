#pragma once

#include "CoreMinimal.h"
#include "Enemies/NexEnemy.h"
#include "Subsystems/WorldSubsystem.h"
#include "EnemiesSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyMulticast, ANexEnemy*, Enemy);

UCLASS(BlueprintType)
class NEXCORE_API UEnemiesSubsystem : public UWorldSubsystem
{
private:
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FEnemyMulticast OnEnemyDeath;

	UFUNCTION(BlueprintPure)
	TArray<ANexEnemy*> GetEnemies() const { return Enemies; }

	UFUNCTION(BlueprintCallable)
	void Add(ANexEnemy* Enemy);

	UFUNCTION(BlueprintCallable)
	void Remove(ANexEnemy* Enemy);

private:

	UPROPERTY()
	TArray<ANexEnemy*> Enemies;
};
