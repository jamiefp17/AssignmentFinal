// Copyright Epic Games, Inc. All Rights Reserved.


#include "AssignmentFinalGameModeBase.h"
#include "CustomPlayerController.h"

void AAssignmentFinalGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	

	StartGame();
}

void AAssignmentFinalGameModeBase::PointScored()
{
	score++;
	UE_LOG(LogTemp, Warning, TEXT("Score: %f"), score);
}

void AAssignmentFinalGameModeBase::playerDied()
{
	EndGame(true);
}

void AAssignmentFinalGameModeBase::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Started Game"));
}

void AAssignmentFinalGameModeBase::EndGame(bool Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Ended Game"));
}
