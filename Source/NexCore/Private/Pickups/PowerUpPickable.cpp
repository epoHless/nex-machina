#include "Pickups/PowerUpPickable.h"

void APowerUpPickable::Deactivate()
{
	Super::Deactivate();
}

APowerUpPickable::APowerUpPickable()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APowerUpPickable::BeginPlay()
{
	Super::BeginPlay();	
}

void APowerUpPickable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
