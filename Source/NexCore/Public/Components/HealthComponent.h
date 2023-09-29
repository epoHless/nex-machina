#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class NEXCORE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Component")
	int32 Health = 1;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(int32 Damage);
	
protected:
	
	UFUNCTION(BlueprintNativeEvent)
	void OnDamageTaken();

	UFUNCTION(BlueprintNativeEvent)
	void OnDeath();
};