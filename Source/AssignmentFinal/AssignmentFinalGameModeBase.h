// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Controller.h"
#include "AssignmentFinalGameModeBase.generated.h"

UCLASS()
class ASSIGNMENTFINAL_API AAssignmentFinalGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	//******************************  PUBLIC  ******************************
public:
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	void BeginPlay();
	UFUNCTION()
		void PointScored(); //An enemy has been defeated, and the score is going to be incremented.
	UFUNCTION()
		void PlayerDied(); //The player character has run out of health, and so the game should end.


	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		float score = 0.0f; //The score that is gained from defeating enemies, determining how well the user has done.


	//******************************  PRIVATE  ******************************
private:
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	UFUNCTION()
		void StartGame(); //Sets up the game ready for the user.
	UFUNCTION()
		void EndGame(bool Value); //Wraps everything up, ending the game.


	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		float scoreBaseIncrementationValue = 1.0f; //The base value that the score will increment by upon the defeat of an enemy.
};
