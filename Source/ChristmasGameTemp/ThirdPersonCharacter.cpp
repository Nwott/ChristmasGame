// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Sleigh.h"
#include "Present.h"

// getters and setters
bool AThirdPersonCharacter::GetInSleigh()
{
	return inSleigh;
}

void AThirdPersonCharacter::SetInSleigh(bool in)
{
	inSleigh = in;
}

bool AThirdPersonCharacter::GetInPickupRange()
{
	return inPickupRange;
}

void AThirdPersonCharacter::SetInPickupRange(bool in)
{
	inPickupRange = in;
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

void AThirdPersonCharacter::OnPressInteract()
{
	if (currPresent == NULL)
	{
		if (inPickupRange)
		{
			GetPresent();
		}
		else
		{
			TArray<APresent*> presents = CheckForPresents();
			APresent* closestPresent = GetClosestPresent(presents);
		}
	}
	else
	{
		DropPresent();
	}
}

void AThirdPersonCharacter::GetPresent()
{
	if (inPickupRange)
	{
		// get present location component position from thirdpersonplayer blueprint
		UStaticMeshComponent* presentLocation = this->FindComponentByTag<UStaticMeshComponent>("PresentLocation");
		const FVector position = presentLocation->GetComponentLocation();

		// spawn present at position
		APresent* present = GetWorld()->SpawnActor<APresent>(presentToSpawn, position, FRotator::ZeroRotator);

		present->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
		currPresent = present;
	}
}

void AThirdPersonCharacter::DropPresent()
{
	if (currPresent == NULL) return;

	UStaticMeshComponent* presentMesh = currPresent->FindComponentByTag<UStaticMeshComponent>("PresentMesh");

	// detach currPresent
	currPresent->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	presentMesh->SetSimulatePhysics(true);
	currPresent = NULL;
}

TArray<APresent*> AThirdPersonCharacter::CheckForPresents()
{
	TArray<APresent*> presents = *(new TArray<APresent*>());
	// get all actors within the collider of player
	TArray<AActor*> collidingActors = *(new TArray<AActor*>());
	GetOverlappingActors(collidingActors);

	for (int i = 0; i < collidingActors.Num(); i++)
	{
		// get class of actor
		UClass* actorClass = collidingActors[i]->GetClass();

		// check if actor is present
		if (actorClass->IsChildOf(APresent::StaticClass()))
		{
			// add present to presents
			presents.Add((APresent*)collidingActors[i]);
		}
	}

	return presents;
}

APresent* AThirdPersonCharacter::GetClosestPresent(TArray<APresent*> presents)
{
	// return if no presents
	if (presents.Num() <= 0) return NULL;

	APresent* closestPresent = presents[0];

	// get distance between present at index 0 and player
	float distance = (this->GetActorLocation() - closestPresent->GetActorLocation()).Size();

	for (int i = 0; i < presents.Num(); i++)
	{
		// get position of present
		APresent* present = presents[i];

		// get distance between present and player
		float presentDistance = (this->GetActorLocation() - closestPresent->GetActorLocation()).Size();

		if (presentDistance < distance)
		{
			closestPresent = present;
			distance = presentDistance;
		}
	}

	return closestPresent;
}
