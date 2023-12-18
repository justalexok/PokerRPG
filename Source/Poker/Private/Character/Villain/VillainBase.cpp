// Copyright Alex Goulder


#include "Character/Villain/VillainBase.h"
#include "AbilitySystem/PokerAbilitySystemComponent.h"
#include "AbilitySystem/PokerAttributeSet.h"

AVillainBase::AVillainBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPokerAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UPokerAttributeSet>("AttributeSet");
}

void AVillainBase::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
