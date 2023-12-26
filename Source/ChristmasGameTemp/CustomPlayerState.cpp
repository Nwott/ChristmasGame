// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerState.h"
#include "Math/UnrealMathUtility.h"

void ACustomPlayerState::CalculateTimeElapsed(float DeltaTime)
{
	timeElapsed += DeltaTime;
	FormatTimeElapsed();
}

FString ACustomPlayerState::FormatTimeElapsed()
{
	FString time = FString::FromInt(timeElapsed) + "s";
	// check if time elapsed has minutes
	if (timeElapsed >= 60)
	{
		int minutes = (int)(FMath::Floor(timeElapsed / 60));
		int seconds = (int)(FMath::Floor(timeElapsed - (minutes * 60)));
	}

	UE_LOG(LogTemp, Display, TEXT("%s"), *time);

	return time;
}
