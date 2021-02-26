// Jamie Pickering - Games Development Assignment 1

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "ForceActor.generated.h"

UCLASS()
class ASSIGNMENTFINAL_API AForceActor : public AActor
{
	GENERATED_BODY()
	
	//******************************  PUBLIC  ******************************
public:	
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	AForceActor();
	UFUNCTION()
		void OnProjectileHit(AActor* box); //Called by the projectile class when a collision has occured.


	//******************************  PRIVATE  ******************************
private:
	//---------------------------------------------------------------------
	//						    COMPONENTS
	//---------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* boxMesh; //Mesh that holds the cube.
	UPROPERTY()
		UPrimitiveComponent* rootComp; //Uses a primitive component, which is what is actually moved when applying physics forces.

};
