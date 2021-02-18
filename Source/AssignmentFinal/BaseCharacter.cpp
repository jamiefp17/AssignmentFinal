// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	playerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Mesh"));
	playerMesh->SetupAttachment(RootComponent);

	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	springArm->SetupAttachment(playerMesh);
	springArm->bUsePawnControlRotation = true;
	springArm->SetRelativeLocation(springArmLocalPosition);
	springArm->SocketOffset = springArmSocketOffset;

	collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	collisionBox->SetupAttachment(playerMesh);
	collisionBox->SetRelativeScale3D(collisionBoxSize);
	collisionBox->SetRelativeLocation(collisionBoxPosition);
	collisionBox->SetCollisionProfileName(collisionBoxName);

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(springArm);

	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	projectileSpawnPoint->SetupAttachment(springArm);
	projectileSpawnPoint->SetRelativeLocation(projectileSpawnLocalPosition);

	playerMovement = CreateDefaultSubobject<UCustomMovementComponent>(TEXT("Player Movement"));

	
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	collisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABaseCharacter::OnOverlapBegin);
	collisionBox->OnComponentEndOverlap.AddDynamic(this, &ABaseCharacter::OnOverlapEnd);

}

void ABaseCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Enter"));
}

void ABaseCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("Exit"));
}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Ouch :'("));
	characterHealth--;
	if (characterHealth < 1.0f)
	{
		Destroy();
	}
	return 1.0f; //CHANGE THIS FROM MAGIC NUMBER
	
}
