// Jamie Pickering - Games Development Assignment 1


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

	//A reference to the cube that will be affected by forces upon collision.
	forceActor = CreateDefaultSubobject<AForceActor>(TEXT("Force Actor"));
}

void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();

	OnActorHit.AddDynamic(this, &AProjectileActor::OnHit); //Dynamic deegate handling landed projectile shots.
}

void AProjectileActor::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	AActor* ProjectileOwner = GetOwner(); //Gets the owner of the projectile.

	if (OtherActor != NULL && ProjectileOwner != NULL) //Makes sure the references aren't null.
	{
		if (OtherActor->GetClass()->IsChildOf(ABaseCharacter::StaticClass())) //An enemy or the player.
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
