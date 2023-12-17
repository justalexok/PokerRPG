// Copyright Alex Goulder


#include "Character/Villain/VillainBase.h"
#include "AbilitySystem/PokerAbilitySystemComponent.h"
#include "AbilitySystem/PokerAttributeSet.h"

AVillainBase::AVillainBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPokerAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UPokerAttributeSet>("AttributeSet");
}
