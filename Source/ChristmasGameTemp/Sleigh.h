// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sleigh.generated.h"

UCLASS()
class CHRISTMASGAMETEMP_API ASleigh : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASleigh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when player leaves sleigh
	UFUNCTION(BlueprintCallable, Category="Sleigh")
	virtual void OnPlayerExit();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
