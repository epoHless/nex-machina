#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ScoreSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FScoreMulticast, float, Score, float, Multiplier);

UCLASS(BlueprintType)
class NEXCORE_API UScoreSubsystem : public UGameInstanceSubsystem
{
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
	float CurrentScore;

	UPROPERTY(EditAnywhere)
	float CurrentMultiplier;
	
public:

	UPROPERTY(BlueprintAssignable)
	FScoreMulticast OnScoreChanged;
	
	UFUNCTION(BlueprintPure, BlueprintCallable)
	float GetScore() const { return CurrentScore; }

	UFUNCTION(BlueprintPure, BlueprintCallable)
	float GetMultiplier() const { return CurrentMultiplier; }

	UFUNCTION(BlueprintCallable)
	void AssignScore(float Score, float Multiplier);
};
