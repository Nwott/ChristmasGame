// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"
#include "CustomMovementComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHRISTMASGAMETEMP_API UCustomMovementComponent : public UFloatingPawnMovement 
{
	GENERATED_BODY()
public:	
	// Sets default values for this component's properties
	UCustomMovementComponent();

protected:
	virtual void BeginPlay() override;
	AActor* actor;
	UClass* actorType;
	APawn* pawn;

	USpringArmComponent* springArm;

	UClass* GetActorType();

	void ApplyGravity();

	UPROPERTY(EditDefaultsOnly, Category="Unstuck")
	float unstuckInterval;

	// where to move the player when they get unstuck
	UPROPERTY(EditDefaultsOnly, Category="Unstuck")
	FVector unstuckDisplacement;

	float unstuckTimer;
	bool canUnstuck = true;

	void UnstuckTimer();

	UFUNCTION(BlueprintCallable, Category="Unstuck")	
	void Unstuck();

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Move(FVector moveDelta);

	// rotates the player
	virtual void HandleCamera();
};
