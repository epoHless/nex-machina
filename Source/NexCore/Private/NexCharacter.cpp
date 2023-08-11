#include "NexCharacter.h"

#include "NexCore/Public/ShootingComponent.h"

ANexCharacter::ANexCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANexCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANexCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANexCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

