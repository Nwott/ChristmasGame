// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "CustomMovementComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHRISTMASGAMETEMP_API UCustomMovementComponent : public UMovementComponent
{
	GENERATED_BODY()
public:	
	// Sets default values for this component's properties
	UCustomMovementComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Move(FVector moveDelta);
};
