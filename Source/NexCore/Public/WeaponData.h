#pragma once

#include "WeaponData.generated.h"

USTRUCT(BlueprintType, DisplayName="Weapon Data")
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FireRate;
};
