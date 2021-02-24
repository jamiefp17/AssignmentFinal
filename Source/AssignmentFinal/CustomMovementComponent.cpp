// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"
#include "BaseCharacter.h"

void UCustomMovementComponent::MoveForwards(float Value)
{
	character = Cast<ABaseCharacter>(GetOwner()); //Casts included class in order to use it. This happens in all of the movement functions.
	character->AddMovementInput(character->GetActorForwardVector() * Value); //Moves along character's forward vector.
}

void UCustomMovementComponent::Strafe(float Value)
{
	character = Cast<ABaseCharacter>(GetOwner());
	character->AddMovementInput(character->GetActorRightVector() * Value); //Moves along character's Rightward vector.
}

void UCustomMovementComponent::Yaw(float Value)
{
	character = Cast<ABaseCharacter>(GetOwner());
	character->AddControllerYawInput(Value); //Changes camera's yaw value (Horizontal).
}

void UCustomMovementComponent::Pitch(float Value)
{
	character = Cast<ABaseCharacter>(GetOwner());
	character->AddControllerPitchInput(Value); //Changes camera's pitch value (Vertical).
}

void UCustomMovementComponent::Fire()
{
	character = Cast<ABaseCharacter>(GetOwner());
	if (character->projectileClass) //Checks to make sure that the character has a projectile class allocated.
	{ 
		spawnLocation = character->projectileSpawnPoint->GetComponentLocation(); //Updates the position that the projectile will spawn in, but finding the world position from its relative one attached to the character.
		spawnRotation = character->projectileSpawnPoint->GetComponentRotation();

		AProjectileActor* TempProjectile = GetWorld()->SpawnActor<AProjectileActor>(character->projectileClass, spawnLocation, spawnRotation); //Spawns the projectile in the determined location.
		TempProjectile->SetOwner(character); //Sets the projectiles owner to the character that shot it. This is required for the ApplyDamage function.
	}
}
