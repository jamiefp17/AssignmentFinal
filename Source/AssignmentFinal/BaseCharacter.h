// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CustomMovementComponent.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ASSIGNMENTFINAL_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UPROPERTY(EditAnywhere)
		UCustomMovementComponent* playerMovement;
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//	// Called to bind functionality to input
//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* playerMesh;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* springArm;
	UPROPERTY(EditAnywhere)
		UCameraComponent* camera;

	UPROPERTY(VisibleAnywhere)
		FVector springArmLocalPosition = { 0.0f, 30.0f, 70.0f };
	UPROPERTY(VisibleAnywhere)
		FVector springArmSocketOffset = { 0.0f, 0.0f, 40.0f };
};