// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CustomMovementComponent.h"
#include "ProjectileActor.h"
#include "Components/BoxComponent.h"
#include "string"
#include "BaseCharacter.generated.h"

UCLASS()
class ASSIGNMENTFINAL_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// Sets default values for this character's properties
	ABaseCharacter();
	void BeginPlay();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere)
		UCustomMovementComponent* playerMovement;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectileActor> projectileClass;
	UPROPERTY(EditAnywhere)
		USceneComponent* projectileSpawnPoint;
	UPROPERTY(EditAnywhere)
		UBoxComponent* collisionBox;

	

private:

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* playerMesh;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* springArm;
	UPROPERTY(EditAnywhere)
		UCameraComponent* camera;
	
	UPROPERTY(VisibleAnywhere)
		FVector collisionBoxSize = { 1.0f, 1.0f, 2.8f };
	UPROPERTY(VisibleAnywhere)
		FVector collisionBoxPosition = { 0.0f, 0.0f, 0.0f };
	UPROPERTY(VisibleAnywhere)
		FName collisionBoxName = "Trigger";


	UPROPERTY(VisibleAnywhere)
		FVector springArmLocalPosition = { 0.0f, 30.0f, 70.0f };
	UPROPERTY(VisibleAnywhere)
		FVector springArmSocketOffset = { 0.0f, 0.0f, 40.0f };
	UPROPERTY(VisibleAnywhere)
		FVector projectileSpawnLocalPosition = { 400.0f, -30.0f, -50.0f };

	UPROPERTY(VisibleAnywhere)
		float characterHealth = 1.0f;
};