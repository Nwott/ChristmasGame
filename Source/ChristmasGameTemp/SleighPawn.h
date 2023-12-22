// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
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
	virtual void HandleMovement();
	virtual void HandleCamera();
	virtual void ApplyGravity();

	UCustomMovementComponent* movement;

	UPROPERTY(BlueprintReadWrite)
	float moveSpeed;

	UPROPERTY(BlueprintReadWrite)
	float gravity;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
