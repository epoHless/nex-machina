#pragma once

#include "CoreMinimal.h"
#include "NexCharacter.h"
#include "UObject/Object.h"
#include "PowerUp.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class NEXCORE_API UPowerUp : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Execute(ANexCharacter* Player);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnRemove(ANexCharacter* Player);
};
