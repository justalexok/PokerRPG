// Copyright Alex Goulder

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PokerUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class POKER_API UPokerUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
