// Fill out your copyright notice in the Description page of Project Settings.


#include "House.h"
#include "ThirdPersonCharacter.h"

// Sets default values
AHouse::AHouse()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHouse::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHouse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHouse::OnPlayerColliderOverlap(AActor* otherActor)
{
	UClass* actorClass = otherActor->GetClass();

	// check if actor collided with is the player
	if (actorClass->IsChildOf(AThirdPersonCharacter::StaticClass()))
	{
	}
}
