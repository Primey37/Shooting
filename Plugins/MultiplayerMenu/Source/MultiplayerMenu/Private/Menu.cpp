// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"
#include "Components/Button.h"
#include "MyGameInstanceSubsystem.h"

void UMenu::MenuSetup()
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;

	UWorld* World = GetWorld();
	if (World) {
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController) {
			//����ģʽ
			FInputModeUIOnly InputModeData;
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			//ָ�����뽹�㣬û�����û�а취�����UI
			InputModeData.SetWidgetToFocus(TakeWidget());
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}
}

bool UMenu::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}
	if (HostButton) {
		HostButton->OnClicked.AddDynamic(this, &UMenu::HostButtonClicked);
	}

	if (JoinButton) {
		JoinButton->OnClicked.AddDynamic(this, &UMenu::JoinButtonClicked);
	}



	return true;
}

void UMenu::HostButtonClicked()
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Blue,
			TEXT("HostButton is clicked")
		);
	}
	UGameInstance* GameInstance = GetGameInstance();
	MultiPlayerSubsystem = GameInstance->GetSubsystem<UMyGameInstanceSubsystem>();
	MultiPlayerSubsystem->CreateSession(4, FString("FreeForAll"));
}

void UMenu::JoinButtonClicked()
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Black,
			TEXT("JoinButton is clicked")
		);
	}
}
