// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Actor.h"
#include "House.generated.h"

UCLASS()
class CHRISTMASGAMETEMP_API AHouse : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHouse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Gets called when player is in box collider of house
	UFUNCTION(BlueprintCallable, Category="House")
	void OnPlayerColliderOverlap(AActor* otherActor);

	UFUNCTION(BlueprintCallable, Category="House")
	void OnPresentColliderEnter(AActor* otherActor);

	UFUNCTION(BlueprintCallable, Category="House")
	void OnPresentColliderExit(AActor* otherActor);

	bool IsPresent(AActor* actor);

	int totalPresents;

	int presents;

	USceneComponent* wPresentCount;
	FVector wPresentCountLoc;

	AActor* player;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
