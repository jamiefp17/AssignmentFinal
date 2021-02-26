// Jamie Pickering - Games Development Assignment 1

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BaseCharacter.h"
#include "CustomMovementComponent.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "CustomPlayerController.generated.h"

//Forward Declarations.
class AAssignmentFinalGameModeBase;

UCLASS()
class ASSIGNMENTFINAL_API ACustomPlayerController : public APlayerController
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
	UPROPERTY(EditAnywhere)
		ABaseCharacter* MyCharacter; //The player character. Acts as an inbetween between the player and the actual movement, taking user input and passing along the information.
	UPROPERTY()
		AAssignmentFinalGameModeBase* gameMode; //A reference to the game mode base. Allows for communication with the game mode, allowing for score incrementation and 

	//subclasses of the HUD for the different screens.
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> gameplayHUDClass; 
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> startupHUDClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> endHUDClass;

	//Uses the userWidget class to make a HUD to show on the screen.
	UPROPERTY()
		UUserWidget* gameplayHUD; 
	UPROPERTY()
		UUserWidget* startupHUD;
	UPROPERTY()
		UUserWidget* endHUD;


	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	virtual void SetupInputComponent(); //Binds inputs to other functions in the class.

	virtual void CallForwards(float Value); //Movement.
	virtual void CallStrafe(float Value);
	virtual void CallYaw(float Value); //Camera rotation.
	virtual void CallPitch(float Value);
	virtual void CallFire(); //Projectile fire.

	UFUNCTION(BlueprintPure)
		int GetScore(); //Used by an updating text box in the HUD to show the most up-to-date score the player has.

	//Changes the screen that's being displayed.
	UFUNCTION(BlueprintCallable)
		void ChangeToGameplayScreen();
	UFUNCTION()
		void ChangeToEndScreen(); //This is the only one that isn't called via a UI button. This is called from the gameModeBase class when it's told the player has died.
	UFUNCTION(BlueprintCallable)
		void ChangeToStartupScreen();

	
	//******************************  PRIVATE  ******************************
private:
	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY()
		FString gameplayScreen = "GameplayScreen"; //Strings that hold the names of the screens we want to switch to.
	UPROPERTY()
		FString startupScreen = "StartupScreen";
	UPROPERTY()
		FString endScreen = "EndScreen";
	

};
