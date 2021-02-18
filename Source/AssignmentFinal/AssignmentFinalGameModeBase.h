// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Controller.h"
#include "AssignmentFinalGameModeBase.generated.h"

class ACustomPlayerController;

/**
 * 
 */
UCLASS()
class ASSIGNMENTFINAL_API AAssignmentFinalGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	void BeginPlay();

	UFUNCTION()
		void PointScored();
	UPROPERTY(VisibleAnywhere)
		float score = 0.0f;

	UFUNCTION()
		void playerDied();

	UPROPERTY(EditAnywhere)
		ACustomPlayerController* player;

	/*UPROPERTY(VisibleAnywhere)
		float playerHealth = player->characterHealth;*/

private:
	UFUNCTION()
		void StartGame();
	UFUNCTION()
		void EndGame(bool Value);
};
