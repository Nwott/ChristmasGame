// Fill out your copyright notice in the Description page of Project Settings.


#include "EndScreenController.h"

#include "Components/TextBlock.h"

void UEndScreenController::UpdateScore(float presentsPerMin, int score)
{
	FString message = "You delivered " + FString::SanitizeFloat(presentsPerMin) + " presents per minute\nwhich results in a score of " + FString::FromInt(score);
	TextScore->SetText(FText::FromString(message));
}
