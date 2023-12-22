// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"
#include "GameFramework/Pawn.h"

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
	actorType = GetActorType();
	
	if (actorType->IsChildOf(APawn::StaticClass()) || actorType == APawn::StaticClass())
	{
		pawn = (APawn*)actor;
	}
}


// Called every frame
void UCustomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	HandleCamera();
}

void UCustomMovementComponent::HandleCamera()
{
	FRotator rotation = *(new FRotator());

	if (pawn != NULL)
	{
		rotation = pawn->GetControlRotation();
	}

	UE_LOG(LogTemp, Display, TEXT("Rotation: %s"), *rotation.ToString());

	actor->SetActorRotation(rotation);
}

void UCustomMovementComponent::Move(FVector moveDelta)
{
	FHitResult* hitResult = new FHitResult();

	//this->SafeMoveUpdatedComponent(moveVector, FQuat::Identity, false, hitResult);
	actor->SetActorLocation(actor->GetActorLocation() + moveDelta, true, hitResult);
}

UClass* UCustomMovementComponent::GetActorType()
{
	return actor->GetClass();
}
