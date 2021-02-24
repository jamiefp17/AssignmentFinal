// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "CustomPlayerController.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	//Mesh that holds the Unreal mannequin model.
	playerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Mesh")); 
	playerMesh->SetupAttachment(RootComponent);

	//A collisionbox that will allow for the detection of projectile 'hits' on the character.
	collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	collisionBox->SetupAttachment(playerMesh);
	collisionBox->SetRelativeScale3D(collisionBoxSize);
	collisionBox->SetCollisionProfileName(collisionBoxName);

	//Holds the camera to the player, dynamically moving if the camera gets pressed against a wall.
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	springArm->SetupAttachment(playerMesh);
	springArm->bUsePawnControlRotation = true; //Allows the pawn to rotate using pitch without keeping the character parallel from the camera.
	springArm->SetRelativeLocation(springArmLocalPosition);
	springArm->SocketOffset = springArmSocketOffset;
	
	//The camera veiwpoint the user see from when playing the game.
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(springArm);
	
	//The point on the character that projectiles will spawn at when being fired.
	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	projectileSpawnPoint->SetupAttachment(springArm);
	projectileSpawnPoint->SetRelativeLocation(projectileSpawnLocalPosition);

	playerMovement = CreateDefaultSubobject<UCustomMovementComponent>(TEXT("Player Movement")); //Uses the CustomMovementComponent, which handles user input, allowing the user to control the character.

	projectile = CreateDefaultSubobject<AProjectileActor>(TEXT("Projectile")); //Uses the pointTrigger, which allows the character to interact with the point providing triggers placed around the map.
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	collisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABaseCharacter::OnOverlapBegin); //Sets the functions as delegates.
	gameModeBaseRef = Cast<AAssignmentFinalGameModeBase>(UGameplayStatics::GetGameMode(GetWorld())); //Casts included class in order to use it.

}

void ABaseCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (ActorHasTag("Player")) //Makes sure the collision only works on the player character.
	{
		if (OtherActor->ActorHasTag("PointTrigger")) //Checks the collision to see if the collision was with a pointTrigger.
		{
			pointTrigger->OnCollisionWithPlayer(OtherActor, gameModeBaseRef); //Calls the collision fuction within the pointTrigger class.
		}
		
	}
}

void ABaseCharacter::PlayProjectileSound()
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), shootingSound, playerMovement->spawnLocation);
	//MAKE ENEMY SHOTS DIFFERENT PITCH BY CHECKING THE TAG
}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{ 
	characterHealth -= projectile->projectileDamage; //The character's health is decreased by the amount of damage the projectile-type it was hit with does.
	if (characterHealth < 1.0f) //The character has run out of health, and is now "dead".
	{
		Destroy(); //The character is removed from the scene.
		if (ActorHasTag("Player")) //Now that the character is gone, we need to decide how the game will react to it. If the character was tagged as being the player, the game should end.
		{
			gameModeBaseRef->PlayerDied();
		}
		else //If it was not the player, that means it must have been an enemy, and a function is called raising the players score.
		{
			gameModeBaseRef->PointScored();
		}
	}
	return projectile->projectileDamage;
}
