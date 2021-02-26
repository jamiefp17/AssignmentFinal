// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

void AEnemyAIController::BeginPlay() 
{
	Super::BeginPlay();

	//playerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//currentWaypoint = ChooseWaypoint();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), waypoints);
	RunBehaviorTree(enemyBehavour);
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentWaypoint = ChooseWaypoint(); //TEMP SOLUTION. MOVE THIS TO A BEHAVOUR TREE FUNCTION LATER
	GetBlackboardComponent()->SetValueAsVector(waypointPosition, currentWaypoint->GetActorLocation());
}

AActor* AEnemyAIController::ChooseWaypoint()
{
	int index = FMath::RandRange(0, waypoints.Num() - 1);
	return waypoints[index];

}

void AEnemyAIController::RaycastToPlayer()
{
	//UE_LOG(LogTemp, Warning, TEXT("Will hit"));
	//enemy = Cast<ABaseCharacter>(GetPawn()); //Needs to get reference here, or it doesn't know what the enemy is.
	//if (enemy != nullptr)
	//{
	//	//UE_LOG(LogTemp, Warning, TEXT("Might hit"));
	//	FVector enemyPositionRaycast = enemy->GetActorLocation();
	//	FVector playerPositionRaycast = playerCharacter->GetActorLocation();

	//	float castRange = 1000.0f;
	//	FHitResult hit;
	//	bool bMissedPlayer = GetWorld()->LineTraceSingleByChannel(hit, enemyPositionRaycast, playerPositionRaycast, ECC_Visibility);

	//	if (!bMissedPlayer)
	//	{
	//		//UE_LOG(LogTemp, Warning, TEXT("Hit something"));
	//		GetBlackboardComponent()->SetValueAsVector(playerPosition, playerCharacter->GetActorLocation());

	//	}
	//	else
	//	{
	//		GetBlackboardComponent()->ClearValue(playerPosition);
	//	}
	//}
	
}

void AEnemyAIController::AttackPlayer()
{
	ABaseCharacter* owner = Cast<ABaseCharacter>(GetPawn());
	if (owner->projectileClass) //Checks to make sure that the character has a projectile class allocated.
	{
		FVector spawnLocation = owner->projectileSpawnPoint->GetComponentLocation(); //Updates the position that the projectile will spawn in, but finding the world position from its relative one attached to the character.
		FRotator spawnRotation = owner->projectileSpawnPoint->GetComponentRotation();

		AProjectileActor* TempProjectile = GetWorld()->SpawnActor<AProjectileActor>(owner->projectileClass, spawnLocation, spawnRotation); //Spawns the projectile in the determined location.
		TempProjectile->SetOwner(owner); //Sets the projectiles owner to the character that shot it. This is required for the ApplyDamage function.
	}
}
