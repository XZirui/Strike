// Copyright (c) XuZirui 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FPSGameMode.generated.h"

/**
 *
 */
UCLASS()
class STRIKE_API AFPSGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AFPSGameMode();

	virtual void BeginPlay() override;
};
