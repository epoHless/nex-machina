
#include "Subsystems/ScoreSubsystem.h"

void UScoreSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentMultiplier = 1;
}

void UScoreSubsystem::AssignScore(float Score, float Multiplier)
{
	CurrentMultiplier += Multiplier;
	const float AdjustedScore = Score * CurrentMultiplier;

	CurrentScore = CurrentScore + AdjustedScore;
	OnScoreChanged.Broadcast(CurrentScore, CurrentMultiplier);
}
