
#include "Subsystems/ScoreSubsystem.h"

void UScoreSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentMultiplier = 1;
}

void UScoreSubsystem::AssignScore(float Score, float Progress)
{
	CurrentProgress += Progress;

	if(CurrentProgress > ProgressToReach)
	{
		CurrentMultiplier++;

		const auto LeftOverProgress = CurrentProgress - ProgressToReach;
		CurrentProgress = 0 + LeftOverProgress;
	}
	
	const float AdjustedScore = Score * CurrentMultiplier;

	CurrentScore = CurrentScore + AdjustedScore;
	OnScoreChanged.Broadcast(CurrentScore, CurrentMultiplier);
}
