// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"

// Sets default values for this component's properties
UCustomMovementComponent::UCustomMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCustomMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	actor = GetOwner();
}


// Called every frame
void UCustomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCustomMovementComponent::Move(FVector moveDelta)
{
	const FVector& moveVector = moveDelta;
	FHitResult* hitResult = new FHitResult();

	//this->SafeMoveUpdatedComponent(moveVector, FQuat::Identity, false, hitResult);
	actor->SetActorLocation(actor->GetActorLocation() + moveVector, true, hitResult);
}

