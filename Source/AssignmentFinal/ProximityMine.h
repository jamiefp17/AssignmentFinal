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

protected:
	void BeginPlay() override;

private:
	UFUNCTION()
		void OnDestruction(const FVector& HitPoint, const FVector& HitDirection);
	
};
