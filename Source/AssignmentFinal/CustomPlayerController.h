// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BaseCharacter.h"
#include "CustomMovementComponent.h"
#include "CustomPlayerController.generated.h"

//Forward Declarations.
class AAssignmentFinalGameModeBase;

UCLASS()
class ASSIGNMENTFINAL_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	//******************************  PROTECTED  ******************************
protected:
	virtual void BeginPlay() override;


	//******************************  PUBLIC  ******************************
public:
	//---------------------------------------------------------------------
	//                    INCLUDES TO OTHER CLASSES
	//---------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		ABaseCharacter* MyCharacter; //The player character. Acts as an inbetween between the player and the actual movement, taking user input and passing along the information.
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> gameplayHUDClass; //A subclass of the HUD for the gameplay screen.
	UPROPERTY()
		UUserWidget* gameplayHUD; //Uses the userWidget class to make a HUD to show on the screen.


	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	virtual void SetupInputComponent(); //Binds inputs to other functions in the class.

	virtual void CallForwards(float Value); //Movement.
	virtual void CallStrafe(float Value);
	virtual void CallYaw(float Value); //Camera rotation.
	virtual void CallPitch(float Value);
	virtual void CallFire(); //Projectile fire.

	UFUNCTION(BlueprintPure)
		int GetScore(); //Used by an updating text box in the HUD to show the most up-to-date score the player has.

	

};
