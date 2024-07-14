// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

UMyGameInstanceSubsystem::UMyGameInstanceSubsystem():
	CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this,&ThisClass::OnCreateSessionComplete)),
	FindSessionsCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this,&ThisClass::OnFindSessionsComplete)),
	JoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this,&ThisClass::OnJoinSessionComplete)),
	StartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this,&ThisClass::OnStartSessionComplete)),
	DestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this,&ThisClass::OnDestroySessionComplete))
{
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	SessionInterface = OnlineSubsystem->GetSessionInterface();
}

void UMyGameInstanceSubsystem::CreateSession(int32 NumPublicConnections, FString MatchType)
{
}

void UMyGameInstanceSubsystem::FindSession(int32 MaxSearchResults)
{
}

void UMyGameInstanceSubsystem::JoinSession(const FOnlineSessionSearchResult& SessionResult)
{
}

void UMyGameInstanceSubsystem::StartSession()
{
}

void UMyGameInstanceSubsystem::DestorySession()
{
}

void UMyGameInstanceSubsystem::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UMyGameInstanceSubsystem::OnFindSessionsComplete(bool bWasSuccessful)
{
}

void UMyGameInstanceSubsystem::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
}

void UMyGameInstanceSubsystem::OnStartSessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UMyGameInstanceSubsystem::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
}
