// Copyright Alex Goulder

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "VillainBase.generated.h"

/**
 * 
 */


UCLASS()
class POKER_API AVillainBase : public ACharacterBase
{
	GENERATED_BODY()
public:
	AVillainBase();

protected:

	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
};
