#include "Enemies/NexEnemy.h"

#include "Components/CapsuleComponent.h"

ANexEnemy::ANexEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
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