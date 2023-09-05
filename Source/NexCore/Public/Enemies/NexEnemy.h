#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ObjectPool/PooledObject.h"
#include "NexEnemy.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class NEXCORE_API ANexEnemy : public APooledObject
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
};