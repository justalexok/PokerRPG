// Copyright Alex Goulder


#include "UI/WidgetControllers/OverlayWidgetController.h"
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
}

void UOverlayWidgetController::BankrollChanged(const FOnAttributeChangeData& Data) const
{
	OnBankrollChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::CoinsChanged(const FOnAttributeChangeData& Data) const
{
	OnCoinsChanged.Broadcast(Data.NewValue);
}

