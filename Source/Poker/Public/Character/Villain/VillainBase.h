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

	//PlayerInterface
	virtual int32 GetLevel() override;

protected:

	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
};
