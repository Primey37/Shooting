// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorB.h"
#include "Kismet/GameplayStatics.h"
#include "Shooting/Public/MyActorA.h"

// Sets default values
AMyActorB::AMyActorB()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMyActorB::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyActorA::StaticClass(), Actors);
	for (auto Actor : Actors) {
		AMyActorA* MyActorA = Cast<AMyActorA>(Actor);
		if (MyActorA) {
			MyActorA->DongTaiDuoBo.AddDynamic(this, &AMyActorB::BeCalledToDongTaiDuoBo);
		}
	}
}

// Called every frame
void AMyActorB::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActorB::BeCalledToDongTaiDuoBo(bool ifOK)
{
	if (ifOK) {
		UE_LOG(LogTemp, Warning, TEXT("success"));
	}
}

