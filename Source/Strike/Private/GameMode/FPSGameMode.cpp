// Copyright (c) XuZirui 2022


#include "GameMode/FPSGameMode.h"

#include "Player/FPSCharacter.h"
#include "Player/FPSPlayerController.h"
#include "State/FPSGameState.h"

AFPSGameMode::AFPSGameMode()
{
	PlayerControllerClass = AFPSPlayerController::StaticClass();
	DefaultPawnClass = AFPSCharacter::StaticClass();
	GameState = TObjectPtr<AFPSGameState>();
}
