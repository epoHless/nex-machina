#pragma once

#include "CoreMinimal.h"
#include "PickableActor.h"
#include "GameFramework/Actor.h"
#include "PowerUps/PowerUp.h"
#include "PowerUpPickable.generated.h"

UCLASS()
class NEXCORE_API APowerUpPickable : public APickableActor
{
	GENERATED_BODY()
public:
	APowerUpPickable();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Power Up")
	TSubclassOf<UPowerUp> PowerUp;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, BlueprintCallable)
	UPowerUp* GetPowerUp() const { return PowerUp.GetDefaultObject(); }
};
