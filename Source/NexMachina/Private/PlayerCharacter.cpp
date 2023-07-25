// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::XMovement(float X)
{
	AddMovementInput(FVector::RightVector * X * movementSpeed);
}

void APlayerCharacter::YMovement(float Y)
{
	AddMovementInput(FVector::ForwardVector * Y * movementSpeed);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("X Movement", this, &APlayerCharacter::XMovement);	
	PlayerInputComponent->BindAxis("Y Movement", this, &APlayerCharacter::YMovement);	
}

