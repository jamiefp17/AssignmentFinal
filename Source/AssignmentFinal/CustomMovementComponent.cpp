// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"

void UCustomMovementComponent::MoveForwards(float Value)
{
	FVector DeltaLocation = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0.0f, 0.0f);
	GetOwner()->AddActorLocalOffset(DeltaLocation, true);
}

void UCustomMovementComponent::Strafe(float Value)
{

}

void UCustomMovementComponent::Yaw(float Value)
{
	float RotateAmount = Value * RotationSpeed * GetWorld()->DeltaTimeSeconds; FRotator Rotation = FRotator(0.0f, RotateAmount, 0.0f);
	FQuat DeltaRotation = FQuat(Rotation);
	GetOwner()->AddActorLocalRotation(DeltaRotation, true);
}

void UCustomMovementComponent::Pitch(float Value)
{

}

void UCustomMovementComponent::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Pressed"));
}
