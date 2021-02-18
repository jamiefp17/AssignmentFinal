// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectileActor.generated.h"

class ABaseCharacter;

UCLASS()
class ASSIGNMENTFINAL_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileActor();
	void BeginPlay();
	/*void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);*/

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

	UPROPERTY(VisibleAnywhere)
		float projectileDamage = 1.0f;

private:
	UFUNCTION()
		void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

};
