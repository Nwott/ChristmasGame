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
	ApplyGravity();
}

void UCustomMovementComponent::HandleCamera()
{
	FRotator rotation = *(new FRotator());

	rotation = pawn->GetControlRotation();


	// remove pitch
	rotation = *(new FRotator(0, rotation.Yaw, rotation.Roll));
	actor->SetActorRotation(rotation);
}

void UCustomMovementComponent::Move(FVector moveDelta)
{
//	FHitResult hitResult(1.f);
	FHitResult* hitResult = new FHitResult();
	

	//this->SafeMoveUpdatedComponent(moveDelta, FQuat::Identity, false, hitResult);
	actor->SetActorLocation(actor->GetActorLocation() + moveDelta, true, hitResult);
}

UClass* UCustomMovementComponent::GetActorType()
{
	return actor->GetClass();
}

void UCustomMovementComponent::ApplyGravity()
{
	FVector gravityVector = *(new FVector(0, 0, -1));

	gravityVector *= 2000 * FApp::GetDeltaTime();

	Move(gravityVector);
}
