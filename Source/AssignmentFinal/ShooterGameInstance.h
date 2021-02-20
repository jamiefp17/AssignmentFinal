// Jamie Pickering - Games Development Assignment 1

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ShooterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENTFINAL_API UShooterGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		float totalScore = 0.0f;

	void Init();

};
