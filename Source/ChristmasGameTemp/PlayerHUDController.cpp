// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDController.h"

void APlayerHUDController::SetHUD(UPlayerHUD* value)
{
	hud = value;
}

UPlayerHUD* APlayerHUDController::GetHUD()
{
	return hud;
}

