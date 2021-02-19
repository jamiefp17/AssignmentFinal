// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "AssignmentFinalGameModeBase.h"

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter = Cast<ABaseCharacter>(GetPawn()); //Casts included class in order to use it.

	gameplayHUD = CreateWidget(this, gameplayHUDClass); //Create the HUD element that will be displayed on the screen.

	if (gameplayHUD != nullptr) //Checks to make sure the HUD isn't pointing to a nullptr, so as not to crash the game.
	{
		gameplayHUD->AddToViewport(); //Displays the HUD on the screen.
	}
}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent); //Input binding based on the project settings set in the editor.
	InputComponent->BindAxis("Move Forwards", this, &ACustomPlayerController::CallForwards);
	InputComponent->BindAxis("Strafe", this, &ACustomPlayerController::CallStrafe);
	InputComponent->BindAxis("Yaw", this, &ACustomPlayerController::CallYaw);
	InputComponent->BindAxis("Pitch", this, &ACustomPlayerController::CallPitch);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACustomPlayerController::CallFire);
}

void ACustomPlayerController::CallForwards(float Value)
{
	if (MyCharacter) //Makes sure that a BaseCharacter has been obtained.
	{
		MyCharacter->playerMovement->MoveForwards(Value); //Passes input along to the customMovement class, which will handle the actual movement.
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

int ACustomPlayerController::GetScore() //This is called by a HUD element.
{
	return MyCharacter->gameModeBaseRef->score; //Finds the current player score, and returns it ready for display.
}
