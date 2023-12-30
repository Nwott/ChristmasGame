// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EndScreenController.h"
#include "GameFramework/PlayerState.h"
#include "CustomPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class CHRISTMASGAMETEMP_API ACustomPlayerState : public APlayerState
{
	GENERATED_BODY()
	
protected:
	float timeElapsed;
	APlayerHUDController* hud;
	int presentsDelivered;
	int presentsLeft;
	int totalPresents;

	UFUNCTION(BlueprintCallable, Category="Player State")
	void CalculateTimeElapsed(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category="Player State")
	FString FormatTimeElapsed();

	UFUNCTION(BlueprintCallable, Category="Player State")
	void SetHUD(APlayerHUDController* value);

	UFUNCTION(BlueprintCallable, Category="Player State")
	void InitialUpdate();

	UPROPERTY(EditDefaultsOnly, Category="HUD")
	TSubclassOf<UEndScreenController> endScreen;
	
	void EndGame();

	bool initialized;

	void UpdateTimeElapsed();
	
public:
	void UpdatePresents(int delta);
	void UpdateTotalPresents(int delta);
};
