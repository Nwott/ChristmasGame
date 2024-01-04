// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ThirdPersonCharacter.h"
#include "Field/FieldSystemComponent.h"
#include "CustomMovementComponent.h"
#include "SleighPawn.generated.h"

UCLASS()
class CHRISTMASGAMETEMP_API ASleighPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASleighPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UCustomMovementComponent* movement;

	UFUNCTION(BlueprintCallable, Category="Sleigh")
	virtual void OnPlayerExit();

	UFUNCTION(BlueprintCallable, Category="Sleigh")
	virtual void OnPlayerPresentPickupEnter(AActor* actor);

	UFUNCTION(BlueprintCallable, Category="Sleigh")
	virtual void OnPlayerPresentPickupExit(AActor* actor);

	UStaticMeshComponent* pickupOutline;

	bool IsPlayer(AActor* actor);

	AThirdPersonCharacter* player;

	// where player sits in sleigh
	USceneComponent* playerLocation;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector GetPlayerLocation();

	void ShowOutline();
	void HideOutline();
};
