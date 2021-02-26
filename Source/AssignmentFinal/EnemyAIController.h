// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine/TargetPoint.h"
#include "BaseCharacter.h"
#include "ProjectileActor.h"
#include "EnemyAIController.generated.h"

UCLASS()
class ASSIGNMENTFINAL_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
	//******************************  PROTECTED  ******************************
protected:
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	virtual void BeginPlay() override;


	//******************************  PUBLIC  ******************************
public:
	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	virtual void Tick(float DeltaTime);

	UFUNCTION(BlueprintCallable)
		void AttackPlayer(); //Tells the enemy to fire at the player character.


	//******************************  PRIVATE  ******************************
private:
	//---------------------------------------------------------------------
	//                    INCLUDES TO OTHER CLASSES
	//---------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		UBehaviorTree* enemyBehavour; //The behavour tree that the enemy uses, controlling movement and attacking.
	UPROPERTY()
		TArray<AActor*> waypoints; //An array of all the waypoints that exist in the world, so the enemies can choose a random one to move to.
	UPROPERTY()
		AActor* currentWaypoint; //The waypoint that the enemy is currently targeting to move towards.


	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	UFUNCTION()
		AActor* ChooseWaypoint(); //Returns a random waypoint that the enemy character will then set as its target.

	
	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY()
		FName waypointPosition = "waypointPosition"; //The name of the waypoint vector that's held in the blackboard.
};
