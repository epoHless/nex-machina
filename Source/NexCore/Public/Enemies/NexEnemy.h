#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NexEnemy.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class NEXCORE_API ANexEnemy : public APawn
{
	GENERATED_BODY()

public:
	ANexEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* CapsuleComponent;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};