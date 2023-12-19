// Copyright Alex Goulder


#include "AbilitySystem/PokerAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"

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
	DOREPLIFETIME_CONDITION_NOTIFY(UPokerAttributeSet, Skill, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPokerAttributeSet, Reputation, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPokerAttributeSet, Popularity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPokerAttributeSet, Style, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPokerAttributeSet, OneTime, COND_None, REPNOTIFY_Always);

}

void UPokerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);
	
}

void UPokerAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	// Source = causer of the effect, Target = target of the effect (owner of this AS)

	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
	
}

void UPokerAttributeSet::OnRep_Bankroll(const FGameplayAttributeData& OldBankroll) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPokerAttributeSet, Bankroll, OldBankroll);
}

void UPokerAttributeSet::OnRep_Coins(const FGameplayAttributeData& OldCoins) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPokerAttributeSet, Coins, OldCoins);

}

void UPokerAttributeSet::OnRep_Skill(const FGameplayAttributeData& OldSkill) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPokerAttributeSet, Coins, OldSkill);

}

void UPokerAttributeSet::OnRep_Reputation(const FGameplayAttributeData& OldReputation) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPokerAttributeSet, Coins, OldReputation);

}

void UPokerAttributeSet::OnRep_Style(const FGameplayAttributeData& OldStyle) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPokerAttributeSet, Coins, OldStyle);

}

void UPokerAttributeSet::OnRep_Popularity(const FGameplayAttributeData& OldPopularity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPokerAttributeSet, Coins, OldPopularity);

}

void UPokerAttributeSet::OnRep_OneTime(const FGameplayAttributeData& OldOneTime) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPokerAttributeSet, Coins, OldOneTime);

}

