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
	
	PlayerInputComponent->BindAxis("X Rotation", this, &ANexCharacter::Rotate);
}

void ANexCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ANexCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void ANexCharacter::Rotate(float Value)
{
	if(Value)
	{
		AddControllerYawInput(Value);
	}
}

