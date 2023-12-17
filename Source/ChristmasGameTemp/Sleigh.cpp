// Fill out your copyright notice in the Description page of Project Settings.


#include "Sleigh.h"
#include "Kismet/GameplayStatics.h"
#include "ThirdPersonCharacter.h"

// Sets default values
ASleigh::ASleigh()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASleigh::BeginPlay()
{
	Super::BeginPlay();
	InitializeVariables();
}

// Called every frame
void ASleigh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASleigh::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASleigh::InitializeVariables()
{
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AThirdPersonCharacter::StaticClass(), actors);
	player = (AThirdPersonCharacter*)actors[0];
}

void ASleigh::OnPlayerExit()
{
	// if player is not in sleigh, then dont run this method
	if (!player->GetInSleigh()) return;

	player->OnExitSleigh();
	player->SetInSleigh(false);
}

void ASleigh::OnPlayerPresentPickupEnter(AActor* actor)
{
	if (IsPlayer(actor))
	{
		player->SetInPickupRange(true);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Entered"));
	}
}

void ASleigh::OnPlayerPresentPickupLeave(AActor* actor)
{
	if (IsPlayer(actor))
	{
		player->SetInPickupRange(false);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Left"));
	}
}

bool ASleigh::IsPlayer(AActor* actor)
{
	UClass* actorClass = actor->GetClass();

	// check if colliding actor is the player
	if (actorClass->IsChildOf(AThirdPersonCharacter::StaticClass()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
