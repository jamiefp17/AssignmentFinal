// Jamie Pickering - Games Development Assignment 1

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BaseCharacter.h"
#include "BTService_RaycastToPlayer.generated.h"

//Forward Declarations.
class AEnemyAIController;

UCLASS()
class ASSIGNMENTFINAL_API UBTService_RaycastToPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()


	//******************************  PROTECTED  ******************************
protected:
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaTime) override;


	//******************************  PRIVATE  ******************************
private:
	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	FName playerPosition = "playerPosition"; //String to use when communicating with the blackboard.
};
