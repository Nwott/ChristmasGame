// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class CHRISTMASGAMETEMP_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TimeElapsedTextBlock;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* PresentsDeliveredTextBlock;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* PresentsLeftTextBlock;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UCanvasPanel* CVFKey;

public:
	void UpdateTimeElapsed(FString text);
	void UpdatePresentsDelivered(FString text);
	void UpdatePresentsLeft(FString text);

	void ChangeFKeyVisibility(bool visible);
};
