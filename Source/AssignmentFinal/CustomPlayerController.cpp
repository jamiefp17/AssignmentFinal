// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "AssignmentFinalGameModeBase.h"

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter = Cast<ABaseCharacter>(GetPawn()); //Casts included class in order to use it.
	

	//Create the HUD element that will be displayed on the screen.
	gameplayHUD = CreateWidget(this, gameplayHUDClass); 
	startupHUD = CreateWidget(this, startupHUDClass);
	endHUD = CreateWidget(this, endHUDClass);

	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == gameplayScreen) //Decides HUD and mouse control depending on the current screen.
	{
		bShowMouseCursor = false;
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(this); //Takes cursor automatically when the screen is switched to.
		if (gameplayHUD != nullptr) //Checks to make sure the HUD isn't pointing to a nullptr, so as not to crash the game.
		{
			gameplayHUD->AddToViewport(); //Displays the HUD on the screen.
		}
	}
	
	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == startupScreen)
	{
		bShowMouseCursor = true; //Allows the user to see their cursor in order to interact with the UI elements.

		if (startupHUD != nullptr)
		{
			startupHUD->AddToViewport();
		}
	}

	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == endScreen)
	{
		bShowMouseCursor = true;
		if (endHUD != nullptr)
		{
			endHUD->AddToViewport();
		}
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
		MyCharacter->PlayProjectileSound();
	}
}

int ACustomPlayerController::GetScore() //This is called by a HUD element.
{
	if (MyCharacter)
	{
		return MyCharacter->gameModeBaseRef->score; //Finds the current player score, and returns it ready for display.
	}
	else return 0;
}

void ACustomPlayerController::ChangeToGameplayScreen()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(gameplayScreen));
	
}

void ACustomPlayerController::ChangeToEndScreen()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(endScreen));
}

void ACustomPlayerController::ChangeToStartupScreen()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(startupScreen));
}