// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine/TargetPoint.h"
#include "EnemyAIController.generated.h"

UCLASS()
class ASSIGNMENTFINAL_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
	//******************************  PROTECTED  ******************************
protected:
	virtual void BeginPlay() override;


	//******************************  PUBLIC  ******************************
public:
	//---------------------------------------------------------------------
	//                    INCLUDES TO OTHER CLASSES
	//---------------------------------------------------------------------
	APawn* playerCharacter; //Automatically aquires the player in order to track.
	


	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	virtual void Tick(float DeltaTime);


	//******************************  PRIVATE  ******************************
private:
	UPROPERTY(EditAnywhere)
		UBehaviorTree* enemyBehavour;
	UPROPERTY()
		FName playerPosition = "playerPosition";
	UPROPERTY()
		TArray<AActor*> waypoints;
	UPROPERTY()
		AActor* currentWaypoint;

	UFUNCTION()
		AActor* ChooseWaypoint();

};
