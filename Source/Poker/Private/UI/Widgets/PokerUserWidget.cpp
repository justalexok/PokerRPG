// Copyright Alex Goulder


#include "UI/Widgets/PokerUserWidget.h"

void UPokerUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}