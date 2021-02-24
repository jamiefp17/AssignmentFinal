// Jamie Pickering - Games Development Assignment 1


#include "PointTrigger.h"
#include "BaseCharacter.h"

APointTrigger::APointTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	//The cube the player will see.
	boxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SetRootComponent(boxMesh);
	boxMesh->SetRelativeScale3D(boxSize);

	//A collision box that acts as a trigger. The player will be able to detect that it has overlapped with the mesh.
	collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	collisionBox->SetupAttachment(boxMesh);
	collisionBox->SetRelativeScale3D(boxSize);
}

void APointTrigger::OnCollisionWithPlayer(AActor* temp, AAssignmentFinalGameModeBase* gameMode)
{
	temp->Destroy(); //Removes the cube from the scene.
	gameMode->PointScored(); //Increments the score.
}

