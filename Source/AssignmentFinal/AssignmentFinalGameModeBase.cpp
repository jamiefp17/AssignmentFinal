// Jamie Pickering - Games Development Assignment 1


#include "AssignmentFinalGameModeBase.h"
#include "CustomPlayerController.h"
#include "BaseCharacter.h"

void AAssignmentFinalGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == gameplayScreen) //Every time the screen is changed, it checks to see if it's the gameplay screen, and calls a function to start the game if it is.
	{
		StartGame();
	}
	controller = Cast<ACustomPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)); //Casts included class in order to use it.
}

void AAssignmentFinalGameModeBase::PointScored()
{
	score += scoreBaseIncrementationValue; //Score is incremented
}

void AAssignmentFinalGameModeBase::PlayerDied()
{
	EndGame(); //So far, this just ends the game. If the player were to be given multiple lives, that would be handled here.
}

void AAssignmentFinalGameModeBase::StartGame()
{
	GetWorld()->GetTimerManager().SetTimer(enemySpawnTimer, this, &AAssignmentFinalGameModeBase::SpawnEnemy, 3.0f, true); //Sets the timer that's used to periodically spawn in enemies.
}

void AAssignmentFinalGameModeBase::EndGame()
{
	controller->ChangeToEndScreen(); //Switches to the lose screen.
}

void AAssignmentFinalGameModeBase::SpawnEnemy()
{
	ABaseCharacter* enemyCharacter = GetWorld()->SpawnActor<ABaseCharacter>(enemyClass, spawnLocation, spawnRotation); //Spawns an enemy at the determined location.
}
