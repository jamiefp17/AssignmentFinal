// Jamie Pickering - Games Development Assignment 1


#include "ProximityMine.h"

void AProximityMine::ProximityMine()
{
	/*boxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	boxMesh->SetupAttachment(RootComponent);*/

	proximityMine = CreateDefaultSubobject<ADestructibleActor>(TEXT("Proximity Mine"));

	/*primitiveComp = CreateDefaultSubobject<UPrimitiveComponent>(TEXT("Primitive Component"));
	primitiveComp->SetupAttachment(RootComponent);
	primitiveComp = Cast<UPrimitiveComponent>(proximityMine);*/

	/*collisionRadius = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Radius"));
	collisionRadius->SetupAttachment(primitiveComp);
	collisionRadius->SetRelativeScale3D(radiusSize);
	collisionRadius->SetCollisionProfileName(collisionRadiusName);*/
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
	UE_LOG(LogTemp, Warning, TEXT("hey, {0}"), primitiveComp);
	
}
