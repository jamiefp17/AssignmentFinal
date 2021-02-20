// Copyright Epic Games, Inc. All Rights Reserved.


#include "AssignmentFinalGameModeBase.h"
#include "CustomPlayerController.h"

void AAssignmentFinalGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	StartGame(); //Runs the game upon level loadup.
	controller = Cast<ACustomPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));;
	/*if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == "StartupScreen")
	{
		UE_LOG(LogTemp, Warning, TEXT("IT WORKED GMB"));
		if (controller)
		{
			controller->bShowMouseCursor = true;
			controller->bEnableClickEvents = true;
			controller->bEnableMouseOverEvents = true;
		}
	}*/
}

void AAssignmentFinalGameModeBase::PointScored()
{
	score += scoreBaseIncrementationValue; //Score is incremented
}

void AAssignmentFinalGameModeBase::PlayerDied() //NOT CURRENTLY IMPLEMENTED
{
	controller->ChangeToEndScreen(); //MOVE TO ENDGAME LATER
	EndGame(true);
}

//void AAssignmentFinalGameModeBase::ChangeToGameplayScreen()
//{
//	UGameplayStatics::OpenLevel(GetWorld(), "GameplayScreen");
//	controller->bShowMouseCursor = false;
//	UWidgetBlueprintLibrary::SetInputMode_GameOnly(controller);
//	controller->startupHUD->RemoveFromViewport();
//	if (controller->gameplayHUD != nullptr) //Checks to make sure the HUD isn't pointing to a nullptr, so as not to crash the game.
//	{
//		controller->gameplayHUD->AddToViewport(); //Displays the HUD on the screen.
//	}
//}

void AAssignmentFinalGameModeBase::StartGame() //NOT CURRENTLY IMPLEMENTED
{
	UE_LOG(LogTemp, Warning, TEXT("Started Game"));
}

void AAssignmentFinalGameModeBase::EndGame(bool Value) //NOT CURRENTLY IMPLEMENTED
{
	UE_LOG(LogTemp, Warning, TEXT("Ended Game"));
	
}
