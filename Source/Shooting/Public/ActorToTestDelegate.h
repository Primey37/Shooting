// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorToTestDelegate.generated.h"

class AShootingCharacter;

UCLASS()
class SHOOTING_API AActorToTestDelegate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorToTestDelegate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void BindDelegateTo();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SayHello();

	FTimerHandle MyTimerHandle;

	UPROPERTY(EditAnywhere)
	AShootingCharacter* ShootingPeople;
};
