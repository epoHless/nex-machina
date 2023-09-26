#pragma once

#include "CoreMinimal.h"
#include "Enemies/EnemyPawn.h"
#include "Enemies/NexEnemy.h"
#include "Subsystems/WorldSubsystem.h"
#include "EnemiesSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyMulticast, ANexEnemy*, Enemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPawnEnemyMulticast, AEnemyPawn*, Enemy);

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

	UPROPERTY(BlueprintAssignable)
	FPawnEnemyMulticast OnEnemyPawnDeath;
	
	UFUNCTION(BlueprintPure)
	TArray<AEnemyPawn*> GetPawnEnemies() const { return PawnEnemies; }
	
	UFUNCTION(BlueprintCallable)
	void AddPawn(AEnemyPawn* Enemy);

	UFUNCTION(BlueprintCallable)
	void RemovePawn(AEnemyPawn* Enemy);

private:

	UPROPERTY()
	TArray<ANexEnemy*> Enemies;

	UPROPERTY()
	TArray<AEnemyPawn*> PawnEnemies;
};
