// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorA.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDongTaiDuoBo, bool, IsOkOrNot);

UCLASS()
class SHOOTING_API AMyActorA : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorA();
	UPROPERTY(BlueprintAssignable)
	FDongTaiDuoBo DongTaiDuoBo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CallDongTaiDuoBo();
};
