// Jamie Pickering - Games Development Assignment 1


#include "ProximityMine.h"

void AProximityMine::ProximityMine()
{
	proximityMine = CreateDefaultSubobject<ADestructibleActor>(TEXT("Proximity Mine"));
}

void AProximityMine::BeginPlay()
{
	Super::BeginPlay();
	OnActorFracture.AddDynamic(this, &AProximityMine::OnDestruction);
}

void AProximityMine::OnDestruction(const FVector& HitPoint, const FVector& HitDirection)
{
	UE_LOG(LogTemp, Warning, TEXT("Hit"));
	UPrimitiveComponent* primitiveComp = Cast<UPrimitiveComponent>(GetRootComponent());
	primitiveComp->AddForce(FVector(5000.0f, 5000.0f, 10000.0f));
	
}
