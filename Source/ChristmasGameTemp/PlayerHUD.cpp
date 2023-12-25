// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

void UPlayerHUD::UpdateTimeElapsed(FString text)
{
	if (TimeElapsedTextBlock)
	{
		TimeElapsedTextBlock->SetText(FText::FromString(text));
	}
}

void UPlayerHUD::UpdatePresentsDelivered(FString text)
{
	if (PresentsDeliveredTextBlock)
	{
		PresentsDeliveredTextBlock->SetText(FText::FromString(text));
	}
}

void UPlayerHUD::UpdatePresentsLeft(FString text)
{
	if (PresentsLeftTextBlock)
	{
		PresentsLeftTextBlock->SetText(FText::FromString(text));
	}
}


