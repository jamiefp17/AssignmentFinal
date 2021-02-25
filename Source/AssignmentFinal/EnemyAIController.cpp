// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

void AEnemyAIController::BeginPlay() 
{
	Super::BeginPlay();

	playerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//currentWaypoint = ChooseWaypoint();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), waypoints);
	RunBehaviorTree(enemyBehavour);
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	playerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); //Finds the character that is selected as player0, which will always be the player character.
	

	//SetFocus(PlayerCharacter); //Looks towards the player.
	//MoveToActor(PlayerCharacter, 500.0f); //Moves within a set distance of the player. REMOVE MAGIC NUMBER LATER IF THIS CODE IS EVEN KEPT.

	
	

	currentWaypoint = ChooseWaypoint(); //TEMP SOLUTION. MOVE THIS TO A BEHAVOUR TREE FUNCTION LATER
	GetBlackboardComponent()->SetValueAsVector(playerPosition, currentWaypoint->GetActorLocation());
}

AActor* AEnemyAIController::ChooseWaypoint()
{
	int index = FMath::RandRange(0, waypoints.Num() - 1);
	return waypoints[index];

}
