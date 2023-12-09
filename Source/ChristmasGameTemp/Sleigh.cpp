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

void ASleigh::OnPlayerExit()
{
	// get controller
	APlayerController* controller = (APlayerController*)GetController();

	controller->UnPossess();

	// find player
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AThirdPersonCharacter::StaticClass(), actors);

	for (AActor* actor : actors)
	{
		controller->Possess((APawn*)actor);
	}
}
