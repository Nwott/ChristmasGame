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

	// get spring arm
	springArm = actor->FindComponentByClass<USpringArmComponent>();
}


// Called every frame
void UCustomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	HandleCamera();
	ApplyGravity();
	UnstuckTimer(DeltaTime);
}

void UCustomMovementComponent::HandleCamera()
{
	FRotator rotation = *(new FRotator());

	rotation = pawn->GetControlRotation();

	float pitch = rotation.Pitch;

	// camera rotation only has pitch
	FRotator cameraRotation = *(new FRotator(pitch, 0, 0));

	// clamp between 270 and 60


	// remove pitch
	rotation = *(new FRotator(0, rotation.Yaw, rotation.Roll));

	FRotator springArmRotation = springArm->GetComponentRotation();
	springArmRotation = *(new FRotator(cameraRotation.Pitch, 0, 0));

	actor->SetActorRotation(rotation);
	springArm->SetRelativeRotation(springArmRotation);
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

void UCustomMovementComponent::UnstuckTimer(float DeltaTime)
{
	if(!canUnstuck)
	{
		unstuckTimer += DeltaTime;

		if (unstuckTimer >= unstuckInterval)
		{
			canUnstuck = true;
		}
	}
}


void UCustomMovementComponent::Unstuck()
{
	UE_LOG(LogTemp, Display, TEXT("1"));
	if (canUnstuck)
	{
		UE_LOG(LogTemp, Display, TEXT("%s"), *unstuckDisplacement.ToString());
		FHitResult* hitResult = new FHitResult();
		actor->SetActorLocation(actor->GetActorLocation() + unstuckDisplacement, false, hitResult,
		                        ETeleportType::TeleportPhysics);
		canUnstuck = false;
		unstuckTimer = 0;
	}
}
