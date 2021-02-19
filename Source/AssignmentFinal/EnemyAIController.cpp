// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

void AEnemyAIController::BeginPlay() 
{
	Super::BeginPlay();

}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); //Finds the character that is selected as player0, which will always be the player character.
	SetFocus(PlayerCharacter); //Looks towards the player.
	MoveToActor(PlayerCharacter, 500.0f); //Moves within a set distance of the player. REMOVE MAGIC NUMBER LATER IF THIS CODE IS EVEN KEPT.
}
