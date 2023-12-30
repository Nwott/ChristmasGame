// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "PlayerHUDController.h"

void APlayerHUDController::SetHUD(UPlayerHUD* value)
{
	hud = value;
}

UPlayerHUD* APlayerHUDController::GetHUD()
{
	return hud;
}

UEndScreenController* APlayerHUDController::MakeEndScreen()
{
	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UEndScreenController* endScreen = CreateWidget<UEndScreenController>(playerController, UEndScreenController::StaticClass());

	return endScreen;
}

