// Copyright Alex Goulder

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PokerAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class POKER_API UPokerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPokerAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Bankroll, Category = "Vital Attributes")
	FGameplayAttributeData Bankroll;
	ATTRIBUTE_ACCESSORS(UPokerAttributeSet, Bankroll);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Coins, Category = "Vital Attributes")
	FGameplayAttributeData Coins;
	ATTRIBUTE_ACCESSORS(UPokerAttributeSet, Coins);



	UFUNCTION()
	void OnRep_Bankroll(const FGameplayAttributeData& OldBankroll) const;

	UFUNCTION()
	void OnRep_Coins(const FGameplayAttributeData& OldCoins) const;
	
};
