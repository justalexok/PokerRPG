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

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

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

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Bankroll, Category = "Vital Attributes")
	FGameplayAttributeData Bankroll;
	ATTRIBUTE_ACCESSORS(UPokerAttributeSet, Bankroll);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Coins, Category = "Vital Attributes")
	FGameplayAttributeData Coins;
	ATTRIBUTE_ACCESSORS(UPokerAttributeSet, Coins);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Skill, Category = "Primary Attributes")
	FGameplayAttributeData Skill;
	ATTRIBUTE_ACCESSORS(UPokerAttributeSet, Skill);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Reputation, Category = "Primary Attributes")
	FGameplayAttributeData Reputation;
	ATTRIBUTE_ACCESSORS(UPokerAttributeSet, Reputation);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Popularity, Category = "Primary Attributes")
	FGameplayAttributeData Popularity;
	ATTRIBUTE_ACCESSORS(UPokerAttributeSet, Popularity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Style, Category = "Primary Attributes")
	FGameplayAttributeData Style;
	ATTRIBUTE_ACCESSORS(UPokerAttributeSet, Style);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_OneTime, Category = "Primary Attributes")
	FGameplayAttributeData OneTime;
	ATTRIBUTE_ACCESSORS(UPokerAttributeSet, OneTime);

	UFUNCTION()
	void OnRep_Bankroll(const FGameplayAttributeData& OldBankroll) const;

	UFUNCTION()
	void OnRep_Coins(const FGameplayAttributeData& OldCoins) const;

	UFUNCTION()
	void OnRep_Skill(const FGameplayAttributeData& OldSkill) const;

	UFUNCTION()
	void OnRep_Reputation(const FGameplayAttributeData& OldReputation) const;

	UFUNCTION()
	void OnRep_Style(const FGameplayAttributeData& OldStyle) const;

	UFUNCTION()
	void OnRep_Popularity(const FGameplayAttributeData& OldPopularity) const;

	UFUNCTION()
	void OnRep_OneTime(const FGameplayAttributeData& OldOneTime) const;

	
private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	
};
