// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"
#include "BaseCharacter.h"
#include "CustomPlayerController.h"

void UCustomMovementComponent::MoveForwards(float Value)
{
	character = Cast<ABaseCharacter>(GetOwner());
	character->AddMovementInput(character->GetActorForwardVector() * Value);
}

void UCustomMovementComponent::Strafe(float Value)
{
	character = Cast<ABaseCharacter>(GetOwner());
	character->AddMovementInput(character->GetActorRightVector() * Value);
}

void UCustomMovementComponent::Yaw(float Value)
{
	character = Cast<ABaseCharacter>(GetOwner());
	character->AddControllerYawInput(Value);
}

void UCustomMovementComponent::Pitch(float Value)
{
	character = Cast<ABaseCharacter>(GetOwner());
	character->AddControllerPitchInput(Value);
}

void UCustomMovementComponent::Fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Fire Pressed"));

	character = Cast<ABaseCharacter>(GetOwner());

	if (character->projectileClass)
	{ 
		FVector SpawnLocation = character->projectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = character->projectileSpawnPoint->GetComponentRotation();
		
		AProjectileActor* TempProjectile = GetWorld()->SpawnActor<AProjectileActor>(character->projectileClass, SpawnLocation, SpawnRotation);
		TempProjectile->SetOwner(character);
	}


}
