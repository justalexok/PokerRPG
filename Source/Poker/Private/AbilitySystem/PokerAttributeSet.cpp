// Copyright Alex Goulder


#include "AbilitySystem/PokerAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UPokerAttributeSet::UPokerAttributeSet()
{
	InitBankroll(100.f);
	InitCoins(50.f);
}

void UPokerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UPokerAttributeSet, Bankroll, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPokerAttributeSet, Coins, COND_None, REPNOTIFY_Always);
}

void UPokerAttributeSet::OnRep_Bankroll(const FGameplayAttributeData& OldBankroll) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPokerAttributeSet, Bankroll, OldBankroll);
}

void UPokerAttributeSet::OnRep_Coins(const FGameplayAttributeData& OldCoins) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPokerAttributeSet, Coins, OldCoins);

}
