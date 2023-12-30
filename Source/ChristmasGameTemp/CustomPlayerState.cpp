// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerState.h"

#include "PlayerHUD.h"
#include "PlayerHUDController.h"
#include "Math/UnrealMathUtility.h"

void ACustomPlayerState::CalculateTimeElapsed(float DeltaTime)
{
	timeElapsed += DeltaTime;
	UpdateTimeElapsed();
}

FString ACustomPlayerState::FormatTimeElapsed()
{
	FString time = FString::FromInt(timeElapsed) + "s";
	
	// check if time elapsed has minutes
	if (timeElapsed >= 60)
	{
		// split time elapsed into minutes and seconds
		int minutes = (int)(FMath::Floor(timeElapsed / 60));
		int seconds = (int)(FMath::Floor(timeElapsed - (minutes * 60)));
		time = FString::FromInt(minutes) + "m " + FString::FromInt(seconds) + "s";
	}

	return time;
}

void ACustomPlayerState::UpdateTimeElapsed()
{
	hud->GetHUD()->UpdateTimeElapsed("Time Elapsed: " + FormatTimeElapsed());
}


void ACustomPlayerState::SetHUD(APlayerHUDController* value)
{
	hud = value;
}

void ACustomPlayerState::EndGame()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Game over"));
	UEndScreenController* end = hud->MakeEndScreen(endScreen);
	TTuple<float, int> scoreTuple = FormatScore();
	end->UpdateScore(scoreTuple.Get<0>(), scoreTuple.Get<1>());
}

void ACustomPlayerState::UpdatePresents(int delta)
{
	presentsDelivered += delta;
	presentsLeft = totalPresents - presentsDelivered;

	// check if presents left is more than zero and also check if hud is initialized
	if(presentsLeft >= 0 && hud)
	{
		if(hud->GetHUD())
		{
			hud->GetHUD()->UpdatePresentsDelivered("Presents Delivered: " + FString::FromInt(presentsDelivered));
			hud->GetHUD()->UpdatePresentsLeft("Presents Left: " + FString::FromInt(presentsLeft));
		}

		if(presentsLeft <= 0)
		{
			EndGame();
		}
	}
}

void ACustomPlayerState::UpdateTotalPresents(int delta)
{
	totalPresents += delta;
}

void ACustomPlayerState::InitialUpdate()
{
	// this method is to update the hud when the game is starting
	// this method is called in the tick method in blueprints
	if(!initialized)
	{
		if(hud)
		{
			if(hud->GetHUD())
			{
				hud->GetHUD()->UpdatePresentsDelivered("Presents Delivered: " + FString::FromInt(presentsDelivered));
				hud->GetHUD()->UpdatePresentsLeft("Presents Left: " + FString::FromInt(presentsLeft));
				initialized = true;
			}
		}
	}
}

TTuple<float, int> ACustomPlayerState::FormatScore()
{
	float presentsPerMin = presentsDelivered / timeElapsed;
	presentsPerMin *= 100;
	presentsPerMin = FMath::Floor(presentsPerMin);
	presentsPerMin /= 100;
	int score = (int)FMath::Floor(presentsPerMin * 727);

	return MakeTuple(presentsPerMin, score);
}
