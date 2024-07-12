// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorToTestDelegate.h"
#include "Kismet/GameplayStatics.h"
#include "shooting/ShootingCharacter.h"

// Sets default values
AActorToTestDelegate::AActorToTestDelegate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AActorToTestDelegate::BeginPlay()
{
	Super::BeginPlay();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	//UE_LOG(LogTemp, Warning, TEXT("%s"),*PlayerPawn->GetName());
	AShootingCharacter* ShootingCharacter = Cast<AShootingCharacter>(PlayerPawn);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *ShootingCharacter->GetName());
	ShootingCharacter->Test.AddDynamic(this, &AActorToTestDelegate::SayHello);

}

void AActorToTestDelegate::BindDelegateTo()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	//UE_LOG(LogTemp, Warning, TEXT("%s"),*PlayerPawn->GetName());
	AShootingCharacter* ShootingCharacter = Cast<AShootingCharacter>(PlayerPawn);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *ShootingCharacter->GetName());
	ShootingCharacter->Test.AddDynamic(this, &AActorToTestDelegate::SayHello);
}

// Called every frame
void AActorToTestDelegate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorToTestDelegate::SayHello()
{
	UE_LOG(LogTemp, Warning, TEXT("hello"));
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1,
			15.f,
			FColor::Black,
			TEXT("Hello")
		);
	}
}

