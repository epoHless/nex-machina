#include "Enemies/NexEnemy.h"

#include "Components/HealthComponent.h"

ANexEnemy::ANexEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

void ANexEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ANexEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANexEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}