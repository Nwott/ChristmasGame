// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EndScreenController.h"
#include "GameFramework/Character.h"
#include "ThirdPersonCharacter.generated.h"

UCLASS()
class CHRISTMASGAMETEMP_API AThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdPersonCharacter();

	UFUNCTION(BlueprintCallable, Category="Sleigh")
	void OnExitSleigh();

	bool GetInSleigh();
	void SetInSleigh(bool in);

	bool GetInPickupRange();
	void SetInPickupRange(bool in);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Possesses sleigh
	UFUNCTION(BlueprintCallable, Category="Sleigh")
	void PossessSleigh();

	void InitializeVariables();

	UPROPERTY(BlueprintReadOnly, Category="Sleigh")
	APlayerController* playerController;

	bool inSleigh;

	void GetPresent();
	void DropPresent();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class APresent> presentToSpawn;

	UFUNCTION(BlueprintCallable, Category="Sleigh")
	void OnPressInteract();

	APresent* currPresent;

	// is player in range of the sleigh present pickup location?
	bool inPickupRange;

	UFUNCTION(BlueprintCallable, Category="Present")
	TArray<APresent*> CheckForPresents();

	APresent* GetClosestPresent(TArray<APresent*>);

	void PickupClosestPresent(APresent* present);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
