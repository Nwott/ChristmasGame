// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	UFUNCTION(BlueprintCallable, Category="Player State")
	void CalculateTimeElapsed(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category="Player State")
	FString FormatTimeElapsed();


};
