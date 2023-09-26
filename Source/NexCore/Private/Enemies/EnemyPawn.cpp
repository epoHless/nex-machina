#include "Enemies/EnemyPawn.h"

AEnemyPawn::AEnemyPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

