// Copyright (c) XuZirui 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CustomSettingSave.generated.h"

#define KEY_MAPPING_SAVE_NAME TEXT("KeyMappingSave")

/**
 * @brief 游戏中的设置存储类，可以对设置进行更改、保存和读取等操作
 */
UCLASS()
class STRIKE_API UCustomSettingSave : public USaveGame
{
	GENERATED_BODY()

public:
	UCustomSettingSave();
	/**
	 * @brief 用户自定义的按键映射
	 */
	UPROPERTY(EditAnywhere, Category="KeyMappings")
	TArray<FInputAxisKeyMapping> CustomKeyMappings;

	/**
	 * @brief 用于保存键位映射自定义设置
	 * @param bSaveDefault 是否为第一次保存
	 */
	void SaveCustomKeyMappingSettings(const bool bSaveDefault = false);

	/**
	 * @brief 用于读取用户的自定义键位映射
	 *        将读取的结果存放在@see CustomKeyMappings中
	 * @return 返回@see CustomKeyMappings
	 */
	TArray<FInputAxisKeyMapping> LoadCustomKeyMappingSettings();
};
