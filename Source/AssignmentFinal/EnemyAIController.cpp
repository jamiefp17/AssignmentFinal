// Jamie Pickering - Games Development Assignment 1


#include "EnemyAIController.h"

void AEnemyAIController::BeginPlay() 
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), waypoints);
	RunBehaviorTree(enemyBehavour);
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentWaypoint = ChooseWaypoint(); //Chooses a waypoint to move to after the previous one has been successful.
	GetBlackboardComponent()->SetValueAsVector(waypointPosition, currentWaypoint->GetActorLocation()); //Sets the waypoint that was chosen as the target in the blackboard component.
}

AActor* AEnemyAIController::ChooseWaypoint()
{
	int index = FMath::RandRange(0, waypoints.Num() - 1); //Random number within the bounds of the number of waypoints.
	return waypoints[index]; //Returns the index number.

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
