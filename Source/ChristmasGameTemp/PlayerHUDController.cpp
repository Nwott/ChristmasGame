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

UEndScreenController* APlayerHUDController::MakeEndScreen(TSubclassOf<UEndScreenController> widget)
{
	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UEndScreenController* endScreen = CreateWidget<UEndScreenController>(
		playerController, widget);
	FInputModeGameAndUI mode;
	mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	mode.SetHideCursorDuringCapture(false);
	playerController->SetInputMode(mode);
	endScreen->AddToViewport(9999);

	return endScreen;	
}

