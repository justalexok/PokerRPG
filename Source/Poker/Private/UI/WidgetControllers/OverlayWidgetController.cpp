// Copyright Alex Goulder


#include "UI/WidgetControllers/OverlayWidgetController.h"

#include "AbilitySystem/PokerAbilitySystemComponent.h"
#include "AbilitySystem/PokerAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UPokerAttributeSet* PokerAttributeSet = CastChecked<UPokerAttributeSet>(AttributeSet);

	OnBankrollChanged.Broadcast(PokerAttributeSet->GetBankroll());
	OnCoinsChanged.Broadcast(PokerAttributeSet->GetCoins());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UPokerAttributeSet* PokerAttributeSet = CastChecked<UPokerAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PokerAttributeSet->GetBankrollAttribute()).AddUObject(this, &UOverlayWidgetController::BankrollChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PokerAttributeSet->GetCoinsAttribute()).AddUObject(this, &UOverlayWidgetController::CoinsChanged);

	Cast<UPokerAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);
			}
		});
}

void UOverlayWidgetController::BankrollChanged(const FOnAttributeChangeData& Data) const
{
	OnBankrollChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::CoinsChanged(const FOnAttributeChangeData& Data) const
{
	OnCoinsChanged.Broadcast(Data.NewValue);
}

