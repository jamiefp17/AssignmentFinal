// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
//#include "Engine/EngineTypes.h"
#include "AssignmentFinalGameModeBase.generated.h"

class ACustomPlayerController;
class ABaseCharacter;

UCLASS()
class ASSIGNMENTFINAL_API AAssignmentFinalGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	//******************************  PUBLIC  ******************************
public:
	//---------------------------------------------------------------------
	//                    INCLUDES TO OTHER CLASSES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		ACustomPlayerController* controller;

	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	void BeginPlay();
	UFUNCTION()
		void PointScored(); //An enemy has been defeated, and the score is going to be incremented.
	UFUNCTION()
		void PlayerDied(); //The player character has run out of health, and so the game should end. Takes the score that the player got before dying.
	/*UFUNCTION(BlueprintCallable)
		void ChangeToGameplayScreen(); */


	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		float score = 0.0f; //The score that is gained from defeating enemies, determining how well the user has done.
	


	//******************************  PRIVATE  ******************************
private:
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseCharacter> enemyClass;
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	UFUNCTION(BlueprintCallable)
		void StartGame(); //Sets up the game ready for the user.
	UFUNCTION()
		void EndGame(); //Wraps everything up, ending the game.
	UFUNCTION(BlueprintCallable)
		void SpawnEnemy();


	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		float scoreBaseIncrementationValue = 1.0f; //The base value that the score will increment by upon the defeat of an enemy.
	UPROPERTY(EditAnywhere)
		FTimerHandle enemySpawnTimer;
	UPROPERTY(VisibleAnywhere)
		FVector spawnLocation = { 0.0f, 0.0f, 0.0f };
	UPROPERTY(VisibleAnywhere)
		FRotator spawnRotation = { 0.0f, 0.0f, 0.0f };
	UPROPERTY()
		FString gameplayScreen = "GameplayScreen";
};
