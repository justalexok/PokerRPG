// Copyright Alex Goulder

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Character/CharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Hero.generated.h"

/**
 * 
 */
UCLASS()
class POKER_API AHero : public ACharacterBase
{
	GENERATED_BODY()

public:
	AHero();

protected:
	UPROPERTY(EditDefaultsOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly)
	float TargetArmLength = 750.f;

	UPROPERTY(EditDefaultsOnly)
	float SpringArmAngle = -45.f;
};
