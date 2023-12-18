// Copyright Alex Goulder


#include "Player/PokerPlayerState.h"
#include "AbilitySystem/PokerAbilitySystemComponent.h"
#include "AbilitySystem/PokerAttributeSet.h"

APokerPlayerState::APokerPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPokerAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UPokerAttributeSet>("AttributeSet");
	NetUpdateFrequency = 100.f;

	
}

UAbilitySystemComponent* APokerPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


