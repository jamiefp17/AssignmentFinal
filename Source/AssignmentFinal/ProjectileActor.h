// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileActor.generated.h"

UCLASS()
class ASSIGNMENTFINAL_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileActor();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* projectileMesh;
	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* projectileMovement;

	UPROPERTY(VisibleAnywhere)
		float projectileSpeed = 2000.0f;
	UPROPERTY(VisibleAnywhere)
		float projectileLife = 3.0f;
	UPROPERTY(VisibleAnywhere)
		FVector projectileSize = {0.3f, 0.3f, 0.3f};

//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;

};
