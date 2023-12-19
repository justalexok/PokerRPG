// Copyright Alex Goulder


#include "Player/PokerPlayerState.h"
#include "AbilitySystem/PokerAbilitySystemComponent.h"
#include "AbilitySystem/PokerAttributeSet.h"
#include "Net/UnrealNetwork.h"

APokerPlayerState::APokerPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPokerAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UPokerAttributeSet>("AttributeSet");
	NetUpdateFrequency = 100.f;

	
}

void APokerPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APokerPlayerState, Level);
}

UAbilitySystemComponent* APokerPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
void APokerPlayerState::OnRep_Level(int32 OldLevel)
{

}

