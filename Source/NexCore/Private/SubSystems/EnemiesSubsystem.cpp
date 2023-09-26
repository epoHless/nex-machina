#include "SubSystems/EnemiesSubsystem.h"

void UEnemiesSubsystem::Add(ANexEnemy* Enemy)
{
	if (!Enemies.Contains(Enemy))
	{
		Enemies.Add(Enemy);
	}
}

void UEnemiesSubsystem::Remove(ANexEnemy* Enemy)
{
	if (Enemies.Contains(Enemy))
	{
		OnEnemyDeath.Broadcast(Enemy);
		Enemies.Remove(Enemy);
	}
}

void UEnemiesSubsystem::AddPawn(AEnemyPawn* Enemy)
{
	if (!PawnEnemies.Contains(Enemy))
	{
		PawnEnemies.Add(Enemy);
	}
}

void UEnemiesSubsystem::RemovePawn(AEnemyPawn* Enemy)
{
	if (PawnEnemies.Contains(Enemy))
	{
		OnEnemyPawnDeath.Broadcast(Enemy);
		PawnEnemies.Remove(Enemy);
	}
}
