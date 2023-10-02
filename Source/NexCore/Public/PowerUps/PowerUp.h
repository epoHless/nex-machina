#pragma once

#include "CoreMinimal.h"
#include "NexCharacter.h"
#include "Components/Image.h"
#include "UObject/Object.h"
#include "PowerUp.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class NEXCORE_API UPowerUp : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power Up")
	bool CanStack = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power Up")
	int CurrentStacks = 1;

	UPROPERTY(EditAnywhere)
	UTexture* PPImage;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Execute(ANexCharacter* Player);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnRemove(ANexCharacter* Player);

	UFUNCTION(BlueprintPure)
	UTexture* GetImage() const { return PPImage; }
};
