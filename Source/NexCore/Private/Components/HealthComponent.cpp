#include "Components/HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::OnDamageTaken_Implementation()
{
}

void UHealthComponent::OnDeath_Implementation()
{
}

void UHealthComponent::TakeDamage(int32 Damage = 1)
{
	Health -= Damage;
	
	OnDamageTaken();
	
	if(Health <= 0)
	{
		OnDeath();
	}
}
