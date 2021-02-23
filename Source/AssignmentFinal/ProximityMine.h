// Jamie Pickering - Games Development Assignment 1

#pragma once

#include "CoreMinimal.h"
#include "DestructibleActor.h"
#include "Components/BoxComponent.h"
#include "Components/PrimitiveComponent.h"
#include "ProximityMine.generated.h"

UCLASS()
class ASSIGNMENTFINAL_API AProximityMine : public ADestructibleActor
{
	GENERATED_BODY()

public:
	void ProximityMine();

	ADestructibleActor* proximityMine;

	/*UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* boxMesh;
	UPROPERTY(EditAnywhere)
		UBoxComponent* collisionRadius;*/
	/*UPROPERTY(VisibleAnywhere)
		UPrimitiveComponent* primitiveComp;*/
protected:
	void BeginPlay() override;
private:
	UFUNCTION()
		void OnDestruction(const FVector& HitPoint, const FVector& HitDirection);
	/*UPROPERTY(VisibleAnywhere)
		FVector radiusSize = { 3.0f, 3.0f, 3.0f };

	UPROPERTY(VisibleAnywhere)
		FName collisionRadiusName = "Mine";*/
	
};
