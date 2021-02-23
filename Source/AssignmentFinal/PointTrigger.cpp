// Jamie Pickering - Games Development Assignment 1


#include "PointTrigger.h"
#include "BaseCharacter.h"

// Sets default values
APointTrigger::APointTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	boxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SetRootComponent(boxMesh);
	boxMesh->SetRelativeScale3D(boxSize);

	collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	collisionBox->SetupAttachment(boxMesh);
	collisionBox->SetRelativeScale3D(boxSize);

	//collisionTag = "PointTrigger";

}

// Called when the game starts or when spawned
void APointTrigger::BeginPlay()
{
	Super::BeginPlay();
	//OnCollisionWithPlayer();
	
}

//void APointTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	UE_LOG(LogTemp, Warning, TEXT("Detected Something"));
//	if (OtherActor->ActorHasTag("Player"))
//	{
//		UE_LOG(LogTemp, Warning, TEXT("HALELUYA spelt it wrong and don't care"));
//	}
//}

void APointTrigger::OnCollisionWithPlayer(AActor* temp)
{
	UE_LOG(LogTemp, Warning, TEXT("Disapear"));
	temp->Destroy();
	
}

