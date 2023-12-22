// Fill out your copyright notice in the Description page of Project Settings.


#include "SleighPawn.h"
#include "Kismet/GameplayStatics.h"
#include "ThirdPersonCharacter.h"

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
	player = (AThirdPersonCharacter*)UGameplayStatics::GetActorOfClass(GetWorld(), AThirdPersonCharacter::StaticClass());
	playerLocation = this->FindComponentByTag<USceneComponent>("PlayerLocation");
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

FVector ASleighPawn::GetPlayerLocation()
{
	return playerLocation->GetComponentLocation();
}

void ASleighPawn::OnPlayerExit()
{
	// if player is not in sleigh, dont run this method
	if (!player->GetInSleigh()) return;

	player->OnExitSleigh();
	player->SetInSleigh(false);
}

void ASleighPawn::OnPlayerPresentPickupEnter(AActor* actor)
{
	if (IsPlayer(actor))
	{
		player->SetInPickupRange(true);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Entered present pickup collision."));
	}
}

void ASleighPawn::OnPlayerPresentPickupExit(AActor* actor)
{
	if (IsPlayer(actor))
	{
		player->SetInPickupRange(false);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Left present pickup collision."));
	}
}

bool ASleighPawn::IsPlayer(AActor* actor)
{
	UClass* actorClass = actor->GetClass();

	// check if colliding actori s the player
	if (actorClass->IsChildOf(AThirdPersonCharacter::StaticClass()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
