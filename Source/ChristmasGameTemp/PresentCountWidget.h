// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PresentCountWidget.generated.h"

/**
 * 
 */
UCLASS()
class CHRISTMASGAMETEMP_API UPresentCountWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* PresentTextBlock;

public:
	void UpdateTextBlock(FString text);
};

