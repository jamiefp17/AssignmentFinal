// Jamie Pickering - Games Development Assignment 1


#include "BTService_RaycastToPlayer.h"
#include "EnemyAIController.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"


void UBTService_RaycastToPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaTime)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaTime);

	AAIController* enemyController = OwnerComp.GetAIOwner();
	
	ABaseCharacter* enemy = Cast<ABaseCharacter>(enemyController->GetPawn()); //Needs to get reference here, or it doesn't know what the enemy is.
	APawn* playerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	FName playerPosition = "playerPosition";

	if (enemy != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Might hit"));
		FVector enemyPositionRaycast = enemy->GetActorLocation();
		FVector playerPositionRaycast = playerCharacter->GetActorLocation();

		float castRange = 1000.0f;
		FHitResult hit;
		bool bMissedPlayer = GetWorld()->LineTraceSingleByChannel(hit, enemyPositionRaycast, playerPositionRaycast, ECC_Visibility);

		if (!bMissedPlayer)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Hit something"));
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(playerPosition, playerCharacter->GetActorLocation());

		}
		else
		{
			OwnerComp.GetBlackboardComponent()->ClearValue(playerPosition);
		}
	}


}