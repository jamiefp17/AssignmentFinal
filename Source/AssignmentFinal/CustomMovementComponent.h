// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASSIGNMENTFINAL_API UCustomMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void MoveForwards(float Value);
	void Strafe(float Value);
	void Yaw(float Value);
	void Pitch(float Value);
	void Fire();
private:
	UPROPERTY(EditAnywhere)
		float MoveSpeed = 100.0f;
	UPROPERTY(EditAnywhere)
		float RotationSpeed = 500.0f;
		
};
