// Copyright Alex Goulder

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetControllers/PokerWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBankrollChangedSignature, float, NewBankroll);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCoinsChangedSignature, float, NewCoins);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)

class POKER_API UOverlayWidgetController : public UPokerWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;

	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnBankrollChangedSignature OnBankrollChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnCoinsChangedSignature OnCoinsChanged;

protected:
	void BankrollChanged(const FOnAttributeChangeData& Data) const;
	void CoinsChanged(const FOnAttributeChangeData& Data) const;
};
