// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileActor.h"
#include "BaseCharacter.h"

// Sets default values
AProjectileActor::AProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	//projectileMesh->SetupAttachment(RootComponent);
	SetRootComponent(projectileMesh);
	projectileMesh->SetRelativeScale3D(projectileSize);
	projectileMesh->SetSimulatePhysics(true);
	projectileMesh->SetNotifyRigidBodyCollision(true);

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	projectileMovement->InitialSpeed = projectileSpeed;
	InitialLifeSpan = projectileLife;
	
}

//void AProjectileActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//
//}
//
//void AProjectileActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//
//}

void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();

	
	OnActorHit.AddDynamic(this, &AProjectileActor::OnHit);

}

void AProjectileActor::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	AActor* ProjectileOwner = GetOwner();

	if (OtherActor != NULL && ProjectileOwner != NULL)
	{
		if (OtherActor->GetClass()->IsChildOf(ABaseCharacter::StaticClass()))
		{

			//UE_LOG(LogTemp, Warning, TEXT("Hit"));
			UGameplayStatics::ApplyDamage(
				OtherActor, //actor that will be damaged
				projectileDamage, //the base damage to apply
				ProjectileOwner->GetInstigatorController(), //controller that caused the damage
				this, //Actor that actually caused the damage
				UDamageType::StaticClass()); //class that describes the damage that was done
			
			Destroy();

		}
	}
	
	
}
