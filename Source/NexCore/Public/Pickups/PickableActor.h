#pragma once

#include "CoreMinimal.h"
#include "NexCharacter.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Pickable.h"
#include "PickableActor.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class NEXCORE_API APickableActor : public AActor, public IPickable
{
	GENERATED_BODY()

public:
	APickableActor();

	UPROPERTY(EditAnywhere)
	class USphereComponent* SphereComponent;
	
protected:
	virtual void BeginPlay() override;


public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Pick Up")
	void OnPickUp(ANexCharacter* Player);
};
