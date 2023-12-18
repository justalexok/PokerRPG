// Copyright Alex Goulder


#include "UI/HUD/PokerHUD.h"
#include "UI/Widgets/PokerUserWidget.h"

void APokerHUD::BeginPlay()
{
	Super::BeginPlay();
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
