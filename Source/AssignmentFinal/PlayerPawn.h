// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CustomMovementComponent.h"
#include "PlayerPawn.generated.h"

UCLASS()
class ASSIGNMENTFINAL_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	UPROPERTY(EditAnywhere)
		UCustomMovementComponent* playerMovement;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* playerMesh;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* springArm;
	UPROPERTY(EditAnywhere)
		UCameraComponent* camera;

};
