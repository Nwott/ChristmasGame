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
}

// Called to bind functionality to input
void ASleighPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
