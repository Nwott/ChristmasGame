// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Sleigh.h"
#include "Present.h"

// getters
bool AThirdPersonCharacter::GetInSleigh()
{
	return inSleigh;
}

void AThirdPersonCharacter::SetInSleigh(bool in)
{
	inSleigh = in;
}

// Sets default values
AThirdPersonCharacter::AThirdPersonCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitializeVariables();
}

// Called every frame
void AThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AThirdPersonCharacter::InitializeVariables()
{
	// get controller
	playerController = (APlayerController*)GetController();
}

void AThirdPersonCharacter::PossessSleigh()
{
	if (inSleigh) return;

	// get all actors of type sleigh
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASleigh::StaticClass(), actors);

	// get first actor which is the only sleigh in the game
	AActor* actor = actors[0];
	ASleigh* sleigh = (ASleigh*)actor;

	FVector playerPosition = sleigh->playerPosition;
	FRotator sleighRotation = sleigh->GetActorRotation();

	// teleport player to playerPosition in sleigh
	Super::TeleportTo(playerPosition, sleighRotation);

	playerController->Possess((APawn*)actor);

	// disable collision for player so it doesnt collide while inside sleigh
	Super::SetActorEnableCollision(false);


	// attach player to sleigh
	// similar to setting transform.parent in unity
	Super::AttachToActor(actor, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	SetInSleigh(true);
}

void AThirdPersonCharacter::OnExitSleigh()
{
	// re-enable collision for player
	Super::SetActorEnableCollision(true);

	// detach player from sleigh
	Super::DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

	playerController->UnPossess();
	playerController->Possess((APawn*)this);
}

void AThirdPersonCharacter::GetPresent()
{
	UStaticMeshComponent* presentLocation = this->FindComponentByTag<UStaticMeshComponent>("PresentLocation");
	const FVector position = presentLocation->GetComponentLocation();
	GetWorld()->SpawnActor<APresent>(presentToSpawn, position, FRotator::ZeroRotator);
}


