﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/SignIn/SignInOverlay.h"
#include "UI/API/GameSessions/JoinGame.h"
#include "Components/Button.h"
#include "UI/Portal/PortalManager.h"

void USignInOverlay::NativeConstruct()
{
	Super::NativeConstruct();
	check(PortalManagerClass);
	check(IsValid(JoinGameWidget));
	check(IsValid(JoinGameWidget->Button_JoinGame));
	
	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);

	JoinGameWidget->Button_JoinGame->OnClicked.AddDynamic(this, &USignInOverlay::OnJoinGameButtonClicked);
}

void USignInOverlay::OnJoinGameButtonClicked()
{
	check(IsValid(PortalManager));
	check(IsValid(JoinGameWidget));
	check(IsValid(JoinGameWidget->Button_JoinGame));

	PortalManager->BroadcastJoinGameSessionMessage.AddDynamic(this, &USignInOverlay::UpdateJoinGamStatusMessage);
	PortalManager->JoinGameSession();
	JoinGameWidget->Button_JoinGame->SetIsEnabled(false);
}

void USignInOverlay::UpdateJoinGamStatusMessage(const FString& StatusMessage)
{
	check(IsValid(JoinGameWidget));
	JoinGameWidget->SetStatusMessage(StatusMessage);
}
