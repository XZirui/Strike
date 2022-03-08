// Copyright (c) XuZirui 2022

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Save/CustomSettingSave.h"
#include "FPSGameInstance.generated.h"

/**
 * @brief 游戏运行过程中的管理类，主要用于操控存储、判定等
 */
UCLASS()
class STRIKE_API UFPSGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFPSGameInstance();

	/**
	 * @brief 游戏设置存储
	 */
	UPROPERTY(BlueprintReadWrite, Category="Save")
	UCustomSettingSave* CustomSettingSave;
};
