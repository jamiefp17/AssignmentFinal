// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectileActor.generated.h"

//Forward declarations.
class ABaseCharacter;

UCLASS()
class ASSIGNMENTFINAL_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
	//******************************  PUBLIC  ******************************
public:	
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	AProjectileActor();
	void BeginPlay();


	//---------------------------------------------------------------------
	//						    COMPONENTS
	//---------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* projectileMesh; //A static mesh that holds the projectile model.
	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* projectileMovement; //The projectileMovementComponent that keeps track of how the projectiles should act, and makes them work.


	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		float projectileDamage = 1.0f; //The damage value the projectiles inflict. Currently the health is 1.0f as well, so a single projectile will kill a character.


	//******************************  PRIVATE  ******************************
private:
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit); //A function which detects when the projectile has had a collision with another object.


	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		float projectileSpeed = 2000.0f; //The speed at which a projecetile travels when initially spawned in.
	UPROPERTY(VisibleAnywhere)
		float projectileLife = 3.0f; //The lifespan in seconds of the projectile.
	UPROPERTY(VisibleAnywhere)
		FVector projectileSize = { 0.3f, 0.3f, 0.3f }; //The scale of the projectile, relative to the sphere static mesh.
};
