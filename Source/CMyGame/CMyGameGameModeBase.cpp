// Copyright Epic Games, Inc. All Rights Reserved.


#include "CMyGameGameModeBase.h"


void ACMyGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	ChanageMenuWidget(StartingWidgetClass);
}


void ACMyGameGameModeBase::ChanageMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrWidget != nullptr)
	{
		CurrWidget->RemoveFromViewport();
		CurrWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrWidget = CreateWidget(GetWorld(), NewWidgetClass);
		//CurrWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrWidget != nullptr)
		{
			CurrWidget->AddToViewport();
		}
	}
}

