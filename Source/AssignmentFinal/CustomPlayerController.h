// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerPawn.h"
#include "CustomMovementComponent.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTFINAL_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	

protected:

	virtual void BeginPlay() override;

public:

	virtual void SetupInputComponent();

	virtual void CallForwards(float Value);
	virtual void CallStrafe(float Value);
	virtual void CallYaw(float Value);
	virtual void CallPitch(float Value);
	virtual void CallFire();

	UPROPERTY(EditAnywhere)
		APlayerPawn* MyCharacter;

};
