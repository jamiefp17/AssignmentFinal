// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "AssignmentFinalGameModeBase.h"

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter = Cast<ABaseCharacter>(GetPawn());

	gameplayHUD = CreateWidget(this, gameplayHUDClass);

	if (gameplayHUD != nullptr)
	{
		gameplayHUD->AddToViewport();
	}
}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);
	InputComponent->BindAxis("Move Forwards", this, &ACustomPlayerController::CallForwards);
	InputComponent->BindAxis("Strafe", this, &ACustomPlayerController::CallStrafe);
	InputComponent->BindAxis("Yaw", this, &ACustomPlayerController::CallYaw);
	InputComponent->BindAxis("Pitch", this, &ACustomPlayerController::CallPitch);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACustomPlayerController::CallFire);
}

void ACustomPlayerController::CallForwards(float Value)
{
	if (MyCharacter)
	{
		MyCharacter->playerMovement->MoveForwards(Value);
	}
}

void ACustomPlayerController::CallStrafe(float Value)
{
	if (MyCharacter)
	{
		MyCharacter->playerMovement->Strafe(Value);
	}
}

void ACustomPlayerController::CallYaw(float Value)
{
	if (MyCharacter)
	{
		MyCharacter->playerMovement->Yaw(Value);
	}
}

void ACustomPlayerController::CallPitch(float Value)
{
	if (MyCharacter)
	{
		MyCharacter->playerMovement->Pitch(Value);
	}
}

void ACustomPlayerController::CallFire()
{
	if (MyCharacter)
	{
		MyCharacter->playerMovement->Fire();
	}
}

int ACustomPlayerController::GetScore()
{
	return MyCharacter->gameModeBaseRef->score;
}
