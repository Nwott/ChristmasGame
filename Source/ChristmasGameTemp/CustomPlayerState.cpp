// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerState.h"

#include "PlayerHUD.h"
#include "PlayerHUDController.h"
#include "Math/UnrealMathUtility.h"

void ACustomPlayerState::CalculateTimeElapsed(float DeltaTime)
{
	timeElapsed += DeltaTime;
	UpdateHUD();
}

FString ACustomPlayerState::FormatTimeElapsed()
{
	FString time = FString::FromInt(timeElapsed) + "s";
	// check if time elapsed has minutes
	if (timeElapsed >= 60)
	{
		int minutes = (int)(FMath::Floor(timeElapsed / 60));
		int seconds = (int)(FMath::Floor(timeElapsed - (minutes * 60)));
		time = FString::FromInt(minutes) + "m " + FString::FromInt(seconds) + "s";
	}

	return time;
}

void ACustomPlayerState::UpdateHUD()
{
	hud->GetHUD()->UpdateTimeElapsed("Time Elapsed: " + FormatTimeElapsed());
}


void ACustomPlayerState::SetHUD(APlayerHUDController* value)
{
	hud = value;
}
