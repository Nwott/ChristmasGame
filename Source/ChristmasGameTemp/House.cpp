// Fill out your copyright notice in the Description page of Project Settings.


#include "House.h"
#include "ThirdPersonCharacter.h"
#include "Present.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "PresentCountWidget.h"
#include "Blueprint/UserWidget.h"

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
	wPresentCount = FindComponentByTag<USceneComponent>("PresentCount");
	wPresentCountLoc = wPresentCount->GetComponentLocation();
	player = UGameplayStatics::GetActorOfClass(GetWorld(), AThirdPersonCharacter::StaticClass());
}

// Called every frame
void AHouse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (wPresentCount != NULL)
	{
		wPresentCount->SetWorldRotation(UKismetMathLibrary::FindLookAtRotation(wPresentCountLoc, player->GetActorLocation()));
	}
}

void AHouse::SetPresentWidget(UPresentCountWidget* widget)
{
	playerState = (ACustomPlayerState*)UGameplayStatics::GetPlayerState(GetWorld(), 0);
	presentCountWidget = widget;
	SetPresents(0);
	SetTotalPresents(FMath::RandRange(1, 3));
	playerState->UpdatePresents(0);
}

void AHouse::OnPlayerColliderOverlap(AActor* otherActor)
{
	UClass* actorClass = otherActor->GetClass();

	// check if actor collided with is the player
	if (actorClass->IsChildOf(AThirdPersonCharacter::StaticClass()))
	{
	}
}

void AHouse::SetPresents(int value)
{
	presents = value;
	FString text = FString::FromInt(presents) + " / " + FString::FromInt(totalPresents);
	UpdatePresentWidget(text);
}

void AHouse::SetTotalPresents(int value)
{
	totalPresents = value;
	FString text = FString::FromInt(presents) + " / " + FString::FromInt(totalPresents);
	UpdatePresentWidget(text);
	playerState->UpdateTotalPresents(value);
}

void AHouse::UpdatePresentWidget(FString text)
{
	presentCountWidget->UpdateTextBlock(text);
}

void AHouse::OnPresentColliderEnter(AActor* otherActor)
{
	if (!IsPresent(otherActor) || presents >= totalPresents) return;

	if (!presentsInHouse.Contains(otherActor))
	{
		UE_LOG(LogTemp, Display, TEXT("Testing"));
		presentsInHouse.Add(otherActor);
		SetPresents(presents + 1);
		playerState->UpdatePresents(1);
	}

}

void AHouse::OnPresentColliderExit(AActor* otherActor)
{

}

bool AHouse::IsPresent(AActor* actor)
{
	// get actor class
	UClass* actorClass = actor->GetClass();

	// check if actor is present
	if (actorClass->IsChildOf(APresent::StaticClass()))
	{
		return true;
	}

	return false;
}
