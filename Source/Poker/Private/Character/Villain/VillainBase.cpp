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

int32 AVillainBase::GetLevel()
{
	return Level;
}

void AVillainBase::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AVillainBase::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UPokerAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();

}
