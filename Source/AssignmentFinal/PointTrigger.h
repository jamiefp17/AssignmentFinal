// Jamie Pickering - Games Development Assignment 1

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PointTrigger.generated.h"

//Forward Declarations.
class ABaseCharacter;

UCLASS()
class ASSIGNMENTFINAL_API APointTrigger : public AActor
{
	GENERATED_BODY()
	
	//******************************  PUBLIC  ******************************
public:	
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	APointTrigger();

	UFUNCTION()
		void OnCollisionWithPlayer(AActor* temp, AAssignmentFinalGameModeBase* gameMode); //Called by the BaseCharacter class when it has detected a collision with a pointTrigger.


	//******************************  PRIVATE  ******************************
private:
	//---------------------------------------------------------------------
	//						    COMPONENTS
	//---------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* boxMesh; //A static mesh that holds the box model.


	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		FVector boxSize = { 0.3f, 0.3f, 0.3f }; //The size of the box.
	UPROPERTY(VisibleAnywhere)
		UBoxComponent* collisionBox; //Allows for the player to detect there has been a collision.

};
