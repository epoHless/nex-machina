#include "Pickups/PickableActor.h"
#include "Components/SphereComponent.h"

APickableActor::APickableActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
}

void APickableActor::BeginPlay()
{
	Super::BeginPlay();
}

void APickableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
