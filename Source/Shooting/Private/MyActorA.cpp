// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorA.h"

// Sets default values
AMyActorA::AMyActorA()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorA::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActorA::CallDongTaiDuoBo()
{
	DongTaiDuoBo.Broadcast(true);
}

