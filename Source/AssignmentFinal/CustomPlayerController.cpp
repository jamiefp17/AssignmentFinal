// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "AssignmentFinalGameModeBase.h"
#include "ShooterGameInstance.h"

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter = Cast<ABaseCharacter>(GetPawn()); //Casts included class in order to use it.

	game = Cast<UShooterGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	

	//Create the HUD element that will be displayed on the screen.
	gameplayHUD = CreateWidget(this, gameplayHUDClass); 
	startupHUD = CreateWidget(this, startupHUDClass);
	endHUD = CreateWidget(this, endHUDClass);

	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == gameplayScreen) //This should actaully be false. But if for whatever reason the game opens on the Gameplay screen, it will still work as intended.
	{
		bShowMouseCursor = false;
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(this);
		if (gameplayHUD != nullptr) //Checks to make sure the HUD isn't pointing to a nullptr, so as not to crash the game.
		{
			gameplayHUD->AddToViewport(); //Displays the HUD on the screen.
		}
	}
	
	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == startupScreen) //This is the screen that should open upon starting the game.
	{
		bShowMouseCursor = true;
		/*bEnableClickEvents = true;
		bEnableMouseOverEvents = true;*/
		//UWidgetBlueprintLibrary::SetInputMode_GameOnly(this);

		if (startupHUD != nullptr)
		{
			startupHUD->AddToViewport();
		}
	}

	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == endScreen)
	{
		bShowMouseCursor = true;
		//UWidgetBlueprintLibrary::SetInputMode_GameOnly(this);
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
	}
}

int ACustomPlayerController::GetScore() //This is called by a HUD element.
{
	if (MyCharacter)
	{
		if (MyCharacter->gameModeBaseRef->score > 0)
		{
			score = MyCharacter->gameModeBaseRef->score;
		}
		return MyCharacter->gameModeBaseRef->score; //Finds the current player score, and returns it ready for display.
	}
	else return 0;
}

void ACustomPlayerController::ChangeToGameplayScreen()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(gameplayScreen));
	//bShowMouseCursor = false;
	//startupHUD->RemoveFromViewport();
	//if (gameplayHUD != nullptr) //Checks to make sure the HUD isn't pointing to a nullptr, so as not to crash the game.
	//{
	//	gameplayHUD->AddToViewport(); //Displays the HUD on the screen.
	//}
	
}

void ACustomPlayerController::ChangeToEndScreen()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(endScreen));
	//bShowMouseCursor = true;
	//UWidgetBlueprintLibrary::SetInputMode_GameOnly(this);
	//gameplayHUD->RemoveFromViewport();
	//if (endHUD != nullptr) //Checks to make sure the HUD isn't pointing to a nullptr, so as not to crash the game.
	//{
	//	endHUD->AddToViewport(); //Displays the HUD on the screen.
	//}
}

void ACustomPlayerController::ChangeToStartupScreen()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(startupScreen));
	//bShowMouseCursor = true;
	//endHUD->RemoveFromViewport();
	//if (startupHUD != nullptr) //Checks to make sure the HUD isn't pointing to a nullptr, so as not to crash the game.
	//{
	//	startupHUD->AddToViewport(); //Displays the HUD on the screen.
	//}
}

int ACustomPlayerController::GetFinalScore()
{
	
	//UE_LOG(LogTemp, Warning, TEXT("Score is currently %f"), score);
	return score;
}

