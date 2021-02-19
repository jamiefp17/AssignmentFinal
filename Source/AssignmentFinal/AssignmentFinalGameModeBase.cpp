// Copyright Epic Games, Inc. All Rights Reserved.


#include "AssignmentFinalGameModeBase.h"

void AAssignmentFinalGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	StartGame(); //Runs the game upon level loadup.
}

void AAssignmentFinalGameModeBase::PointScored()
{
	score += scoreBaseIncrementationValue; //Score is incremented
}

void AAssignmentFinalGameModeBase::PlayerDied() //NOT CURRENTLY IMPLEMENTED
{
	EndGame(true);
}

void AAssignmentFinalGameModeBase::StartGame() //NOT CURRENTLY IMPLEMENTED
{
	UE_LOG(LogTemp, Warning, TEXT("Started Game"));
}

void AAssignmentFinalGameModeBase::EndGame(bool Value) //NOT CURRENTLY IMPLEMENTED
{
	UE_LOG(LogTemp, Warning, TEXT("Ended Game"));
}
