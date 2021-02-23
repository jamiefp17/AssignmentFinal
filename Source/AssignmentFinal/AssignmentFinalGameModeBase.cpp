// Copyright Epic Games, Inc. All Rights Reserved.


#include "AssignmentFinalGameModeBase.h"
#include "CustomPlayerController.h"
#include "BaseCharacter.h"

void AAssignmentFinalGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == gameplayScreen)
	{
		StartGame();
	}
	controller = Cast<ACustomPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));;
	/*if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == "StartupScreen")
	{
		UE_LOG(LogTemp, Warning, TEXT("IT WORKED GMB"));
		if (controller)
		{
			controller->bShowMouseCursor = true;
			controller->bEnableClickEvents = true;
			controller->bEnableMouseOverEvents = true;
		}
	}*/
}

void AAssignmentFinalGameModeBase::PointScored()
{
	score += scoreBaseIncrementationValue; //Score is incremented
}

void AAssignmentFinalGameModeBase::PlayerDied() //NOT CURRENTLY IMPLEMENTED
{
	controller->ChangeToEndScreen(); //MOVE TO ENDGAME LATER
	EndGame();
}

//void AAssignmentFinalGameModeBase::ChangeToGameplayScreen()
//{
//	UGameplayStatics::OpenLevel(GetWorld(), "GameplayScreen");
//}

void AAssignmentFinalGameModeBase::StartGame() //NOT CURRENTLY IMPLEMENTED
{
	UE_LOG(LogTemp, Warning, TEXT("Started Game"));

	GetWorld()->GetTimerManager().SetTimer(enemySpawnTimer, this, &AAssignmentFinalGameModeBase::SpawnEnemy, 3.0f, true);
}

void AAssignmentFinalGameModeBase::EndGame() //NOT CURRENTLY IMPLEMENTED
{
	UE_LOG(LogTemp, Warning, TEXT("Ended Game"));
	
}

void AAssignmentFinalGameModeBase::SpawnEnemy()
{
	ABaseCharacter* enemyCharacter = GetWorld()->SpawnActor<ABaseCharacter>(enemyClass, spawnLocation, spawnRotation);
}
