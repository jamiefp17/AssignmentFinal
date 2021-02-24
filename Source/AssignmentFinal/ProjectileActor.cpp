// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileActor.h"
#include "BaseCharacter.h"

AProjectileActor::AProjectileActor()
{
	PrimaryActorTick.bCanEverTick = false;

	//A static mesh that holds the projectile model.
	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	SetRootComponent(projectileMesh);
	projectileMesh->SetRelativeScale3D(projectileSize);
	projectileMesh->SetSimulatePhysics(true);
	projectileMesh->SetNotifyRigidBodyCollision(true);

	//The projectileMovementComponent that keeps track of how the projectiles should act, and makes them work.
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	projectileMovement->InitialSpeed = projectileSpeed;
	InitialLifeSpan = projectileLife;

	forceActor = CreateDefaultSubobject<AForceActor>(TEXT("Force Actor"));
}

void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();

	OnActorHit.AddDynamic(this, &AProjectileActor::OnHit); //Dynamic deegate.
}

void AProjectileActor::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	AActor* ProjectileOwner = GetOwner(); //Gets the owner of the projectile.

	if (OtherActor != NULL && ProjectileOwner != NULL) //Makes sure the references aren't null.
	{
		if (OtherActor->GetClass()->IsChildOf(ABaseCharacter::StaticClass()))
		{
			UGameplayStatics::ApplyDamage(OtherActor, projectileDamage, ProjectileOwner->GetInstigatorController(), this, UDamageType::StaticClass()); //Uses the applyDamage function.
			
			Destroy(); //Removes projectile if it has hit anything.
		}
		else if (OtherActor->ActorHasTag(forceBox)) //Hit the cube that has forces
		{
			forceActor->OnProjectileHit(OtherActor); //Calls the function to show off forces.
		}
	}
}
