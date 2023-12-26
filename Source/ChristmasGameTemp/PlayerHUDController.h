// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerHUD.h"
#include "GameFramework/HUD.h"
#include "PlayerHUDController.generated.h"

/**
 * 
 */
UCLASS()
class CHRISTMASGAMETEMP_API APlayerHUDController : public AHUD
{
	GENERATED_BODY()
	
protected:
	UPlayerHUD* hud;

	UFUNCTION(BlueprintCallable, Category="HUD")
	void SetHUD(UPlayerHUD* value);

public:
	UPlayerHUD* GetHUD();
};
