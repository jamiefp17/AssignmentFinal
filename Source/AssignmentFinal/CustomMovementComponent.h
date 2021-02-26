//// Jamie Pickering - Games Development Assignment 1

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomMovementComponent.generated.h"

//Forward Declarations.
class ABaseCharacter;


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


	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY()
		FVector spawnLocation; //World space projectile will spawn at.
	UPROPERTY()
		FRotator spawnRotation; //Rotation projectile will spawn facing.
};
