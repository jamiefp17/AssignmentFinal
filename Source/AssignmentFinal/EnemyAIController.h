// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
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
	APawn* PlayerCharacter;


	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	virtual void Tick(float DeltaTime);

	

};
