// Copyright Alex Goulder

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PokerHUD.generated.h"

class UPokerUserWidget;
/**
 * 
 */
UCLASS()
class POKER_API APokerHUD : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TObjectPtr<UPokerUserWidget>  OverlayWidget;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UPokerUserWidget> OverlayWidgetClass;
};
