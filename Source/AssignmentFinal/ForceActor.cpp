// Jamie Pickering - Games Development Assignment 1


#include "ForceActor.h"

// Sets default values
AForceActor::AForceActor()
{
	PrimaryActorTick.bCanEverTick = false;

	boxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	boxMesh->SetupAttachment(RootComponent);
}

void AForceActor::OnProjectileHit(AActor* box)
{
	rootComp = Cast<UPrimitiveComponent>(box->GetRootComponent()); //Casts the root component to a primitive component.
	rootComp->SetSimulatePhysics(true); //Allows physics simulation.
	rootComp->AddImpulse(FVector(-500.0f, 0.0f, 1000.0f) * rootComp->GetMass()); //Moves the cube with forces.
}

