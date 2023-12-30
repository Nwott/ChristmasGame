// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndScreenController.generated.h"

/**
 * 
 */
UCLASS()
class CHRISTMASGAMETEMP_API UEndScreenController : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadonly, meta = (BindWidget))
	class UTextBlock* TextScore;

public:
	void UpdateScore(float presentsPerMin, int score);
};
