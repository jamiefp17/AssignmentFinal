// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileActor.h"

// Sets default values
AProjectileActor::AProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	projectileMesh->SetupAttachment(RootComponent);
	projectileMesh->SetRelativeScale3D(projectileSize);
	projectileMesh->SetSimulatePhysics(true);

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	projectileMovement->InitialSpeed = projectileSpeed;
	InitialLifeSpan = projectileLife;
	
}

// Called when the game starts or when spawned
//void AProjectileActor::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void AProjectileActor::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

