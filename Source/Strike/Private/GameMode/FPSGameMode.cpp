// Copyright (c) XuZirui 2022


#include "GameMode/FPSGameMode.h"

#include "Player/FPSCharacter.h"
#include "Player/FPSPlayerController.h"
#include "State/FPSGameState.h"

AFPSGameMode::AFPSGameMode()
{
	PlayerControllerClass = AFPSPlayerController::StaticClass();
	DefaultPawnClass = ConstructorHelpers::FClassFinder<AFPSCharacter>(
		TEXT("/Game/FirstPerson/Blueprints/FPSCharacter_BP")).Class;
}

void AFPSGameMode::BeginPlay()
{
	Super::BeginPlay();
	GameState = GetWorld()->SpawnActor<AFPSGameState>();
}
