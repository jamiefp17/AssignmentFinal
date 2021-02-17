// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTFINAL_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime);

	APawn* PlayerCharacter;

};
