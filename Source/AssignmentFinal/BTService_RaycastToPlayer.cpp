// Jamie Pickering - Games Development Assignment 1


#include "BTService_RaycastToPlayer.h"
#include "EnemyAIController.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"


void UBTService_RaycastToPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaTime)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaTime);

	AAIController* enemyController = OwnerComp.GetAIOwner(); //Gets the controller for the enemy AI.
	
	ABaseCharacter* enemy = Cast<ABaseCharacter>(enemyController->GetPawn()); //A reference to the enemy that is looking for the player.
	APawn* playerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); //Finds the player character.

	if (enemy != nullptr) //Check to prevent crashing.
	{
		FVector enemyPositionRaycast = enemy->GetActorLocation(); //Location of the enemy.
		FVector playerPositionRaycast = playerCharacter->GetActorLocation(); //Location of the player.

		FHitResult hit; //Used to detect what has been hit by the raytrace.
		bool bMissedPlayer = GetWorld()->LineTraceSingleByChannel(hit, enemyPositionRaycast, playerPositionRaycast, ECC_Visibility); //Setting a bool to check if there is line of sight with the player.

		if (!bMissedPlayer)
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(playerPosition, playerCharacter->GetActorLocation()); //If there is line of sight, update the known location of the player.
		}
		else
		{
			OwnerComp.GetBlackboardComponent()->ClearValue(playerPosition); //Wipe the enemies knowledge of the player's location.
		}
	}
}