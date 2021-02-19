// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomMovementComponent.generated.h"

//Forward Declarations.
class ABaseCharacter;
class ACustomPlayerController;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASSIGNMENTFINAL_API UCustomMovementComponent : public UActorComponent
{
	GENERATED_BODY()

	//******************************  PUBLIC  ******************************
public:	
	//---------------------------------------------------------------------
	//                    INCLUDES TO OTHER CLASSES
	//---------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		ABaseCharacter* character; //An instance of a character, used as the object which the code will move.


	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	void MoveForwards(float Value); //Movement.
	void Strafe(float Value);
	void Yaw(float Value); //Camera rotation.
	void Pitch(float Value);
	void Fire(); //Projectile firing.
};
