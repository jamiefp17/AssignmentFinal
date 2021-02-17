// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

void AEnemyAIController::BeginPlay() 
{
	Super::BeginPlay();

}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	SetFocus(PlayerCharacter);
	MoveToActor(PlayerCharacter, 500.0f);
}
