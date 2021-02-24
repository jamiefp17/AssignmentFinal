// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AssignmentFinalGameModeBase.generated.h"

//Forward Declarations.
class ACustomPlayerController;
class ABaseCharacter;

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
		void PlayerDied(); //The player character has run out of health, and so the game should end. Takes the score that the player got before dying.


	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		float score = 0.0f; //The score that is gained from defeating enemies and collecting pointTriggers, determining how well the user has done.
	


	//******************************  PRIVATE  ******************************
private:
	//---------------------------------------------------------------------
	//                    INCLUDES TO OTHER CLASSES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		ACustomPlayerController* controller; //As the UI interfaces with the playerController, the scene changes occur in that class, so we need to reference it here.
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseCharacter> enemyClass; //A subclass of the enemy blueprint, used to spawn enemies in the scene.


	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	UFUNCTION()
		void StartGame(); //Sets up the game.
	UFUNCTION()
		void EndGame(); //Wraps everything up, ending the game.
	UFUNCTION()
		void SpawnEnemy();
	

	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		float scoreBaseIncrementationValue = 1.0f; //The base value that the score will increment by upon the defeat of an enemy.
	UPROPERTY(EditAnywhere)
		FTimerHandle enemySpawnTimer; //The timer used to spawn enemies periodically.
	UPROPERTY(VisibleAnywhere)
		FVector spawnLocation = { 0.0f, 0.0f, 0.0f }; //The location that enemies will spawn.
	UPROPERTY(VisibleAnywhere)
		FRotator spawnRotation = { 0.0f, 0.0f, 0.0f }; //The rotation of the enemies when they spawn.
	UPROPERTY()
		FString gameplayScreen = "GameplayScreen"; //A string holding the name of the screen we want to switch to.
};
