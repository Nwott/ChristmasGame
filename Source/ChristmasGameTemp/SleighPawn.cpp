// Fill out your copyright notice in the Description page of Project Settings.


#include "SleighPawn.h"

// Sets default values
ASleighPawn::ASleighPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASleighPawn::BeginPlay()
{
	Super::BeginPlay();
	movement = this->FindComponentByClass<UCustomMovementComponent>();
}

// Called every frame
void ASleighPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//HandleMovement();
	//HandleCamera();
	//ApplyGravity();
}

// Called to bind functionality to input
void ASleighPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASleighPawn::HandleMovement()
{
	// reset movement input vector
	ConsumeMovementInputVector();

	// get movement input vector
	FVector moveVector = GetLastMovementInputVector();
	moveVector.Normalize();

	// multiply moveVector by delta time and moveSpeed
	// i dont know if you need to multiply it by delta time or if it is already multiplied when you
	// get it from GetPendingMovementInputVector
	moveVector *= FApp::GetDeltaTime() * moveSpeed;

	movement->Move(moveVector);
}

void ASleighPawn::HandleCamera()
{
	// get controller rotation
	FRotator rotation = this->GetControlRotation();

	//movement->HandleCamera(rotation);
}

void ASleighPawn::ApplyGravity()
{
	FVector gravityVector = *(new FVector(0, 0, -1));

	gravityVector *= gravity;

	movement->Move(gravityVector);
}
