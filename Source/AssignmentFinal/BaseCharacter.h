// Jamie Pickering - Games Development Assignment 1

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CustomMovementComponent.h"
#include "ProjectileActor.h"
#include "Components/BoxComponent.h"
#include "AssignmentFinalGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Sound/SoundBase.h"
#include "PointTrigger.h"
#include "BaseCharacter.generated.h"

//Forward Declarations.
class ACustomPlayerController;

UCLASS()
class ASSIGNMENTFINAL_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	//******************************  PUBLIC  ******************************
public:
	//---------------------------------------------------------------------
	//                    INCLUDES TO OTHER CLASSES
	//---------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		UCustomMovementComponent* playerMovement; //Uses the CustomMovementComponent, which handles user input, allowing the user to control the character.
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectileActor> projectileClass; //Subclass of a generic projectile class, allowing me to be specific, without restricting all of the projectiles that could be implimented.
	UPROPERTY()
		AAssignmentFinalGameModeBase* gameModeBaseRef; //Uses the gameModeBase, which allows for information to pass between the game mode, and the characters. 
													   //This would include awarding 'score' when enemies are killed, and ending the game when the player character dies.
	UPROPERTY()
	APointTrigger* pointTrigger; //Uses the pointTrigger, which allows the character to interact with the point providing triggers placed around the map.


	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	ABaseCharacter();
	void BeginPlay();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); //Detects when a collision has occured with a character.
	UFUNCTION()
		void PlayProjectileSound(); //Called by the playerMovement class to play the projectile shooting sound.

	
	//---------------------------------------------------------------------
	//						    COMPONENTS
	//---------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		USceneComponent* projectileSpawnPoint; //The point on the character that projectiles will spawn at when being fired.
	UPROPERTY(EditAnywhere)
		UBoxComponent* collisionBox; //A collisionbox that will allow for the detection of projectile 'hits' on the character.

	
	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		float characterHealth = 1.0f; //The health that characters have. This is the same for the player and enemies.
	UPROPERTY(VisibleAnywhere)
		float damageOutput = 1.0f; //How much damage a projectile does in one hit.


	//******************************  PRIVATE  ******************************
private:
	//---------------------------------------------------------------------
	//                    INCLUDES TO OTHER CLASSES
	//---------------------------------------------------------------------
	AProjectileActor* projectile; //Allows access to the damage value to use when applying damage.


	//---------------------------------------------------------------------
	//                            FUNCTIONS
	//---------------------------------------------------------------------
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override; //Function that fires when a character has been hit by a projectile.


	//---------------------------------------------------------------------
	//						    COMPONENTS
	//---------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* playerMesh; //Mesh that holds the Unreal mannequin model.
	UPROPERTY(EditAnywhere)
		USpringArmComponent* springArm; //Holds the camera to the player, dynamically moving if the camera gets pressed against a wall.
	UPROPERTY(EditAnywhere)
		UCameraComponent* camera; //The camera veiwpoint the user see from when playing the game.
	UPROPERTY(EditAnywhere)
		USoundBase* shootingSound; //The sound that is played when a projectile is fired.
	

	//---------------------------------------------------------------------
	//						       VARIABLES
	//---------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere)
		FVector collisionBoxSize = { 1.0f, 1.0f, 2.8f }; //The scale for the character collisionbox.
	UPROPERTY(VisibleAnywhere)
		FName collisionBoxName = "Trigger"; //Name applied to the collisionbox.
	UPROPERTY(VisibleAnywhere)
		FVector springArmLocalPosition = { 0.0f, 30.0f, 70.0f }; //The relative position of the spring arm from the mesh.
	UPROPERTY(VisibleAnywhere)
		FVector springArmSocketOffset = { 0.0f, 0.0f, 40.0f }; //The socket offset for the spring arm, lifting the camera so it doesn't just look dead on.
	UPROPERTY(VisibleAnywhere)
		FVector projectileSpawnLocalPosition = { 400.0f, -30.0f, -50.0f }; //The relative position of the projectile spawn-point from the spring arm.
	UPROPERTY()
		FName player = "Player";
};