#include "NexCharacter.h"

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

	PlayerInputComponent->BindAxis("X Movement", this, &ANexCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Y Movement", this, &ANexCharacter::MoveRight);
}

void ANexCharacter::MoveRight(float Y)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Y);
}

void ANexCharacter::MoveForward(float X)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, X);
}

