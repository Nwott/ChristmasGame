// Fill out your copyright notice in the Description page of Project Settings.


#include "PresentCountWidget.h"

void UPresentCountWidget::UpdateTextBlock(FString text)
{
	if (PresentTextBlock != NULL)
	{
		PresentTextBlock->SetText(FText::FromString(text));
	}
}
