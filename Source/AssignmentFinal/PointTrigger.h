// Jamie Pickering - Games Development Assignment 1

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PointTrigger.generated.h"

class ABaseCharacter;

UCLASS()
class ASSIGNMENTFINAL_API APointTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointTrigger();

	UFUNCTION()
		void OnCollisionWithPlayer(AActor* temp);
	/*UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);*/


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

private:
	

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* boxMesh;
	UPROPERTY(VisibleAnywhere)
		FVector boxSize = { 0.3f, 0.3f, 0.3f };
	UPROPERTY(VisibleAnywhere)
		UBoxComponent* collisionBox;

};
