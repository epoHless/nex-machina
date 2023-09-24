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
