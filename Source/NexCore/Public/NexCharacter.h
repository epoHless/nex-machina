#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NexCharacter.generated.h"

UCLASS(Blueprintable, BlueprintType)
class NEXCORE_API ANexCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ANexCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveRight(float Value);
	void MoveForward(float Value);

	void Rotate(float Value);

};
