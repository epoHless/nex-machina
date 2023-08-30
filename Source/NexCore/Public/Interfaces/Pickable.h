#pragma once

#include "CoreMinimal.h"
#include "NexCharacter.h"
#include "UObject/Interface.h"
#include "Pickable.generated.h"

UINTERFACE(Blueprintable, BlueprintType)
class UPickable : public UInterface
{
	GENERATED_BODY()
};

class NEXCORE_API IPickable
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Pick Up")
	void OnPickup(ANexCharacter* Player);
};