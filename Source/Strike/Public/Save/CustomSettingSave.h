// Copyright (c) XuZirui 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CustomSettingSave.generated.h"

#define KEY_MAPPING_SAVE_NAME TEXT("KeyAxisMappingSave")

#define DEFAULT_AXIS_MAPPINGS { \
				/* 前后移动 */ \
				FInputAxisKeyMapping("Move Forward / Backward", EKeys::W, 1.0f), \
				FInputAxisKeyMapping("Move Forward / Backward", EKeys::S, -1.0f), \
				\
				/* 前后移动（手柄）*/ \
				FInputAxisKeyMapping("Move Forward / Backward", EKeys::Gamepad_LeftY, 1.0f), \
				\
				/* 左右移动 */ \
				FInputAxisKeyMapping("Move Right / Left", EKeys::D, 1.0f), \
				FInputAxisKeyMapping("Move Right / Left", EKeys::A, -1.0f), \
				\
				/* 左右移动（手柄） */ \
				FInputAxisKeyMapping("Move Right / Left", EKeys::Gamepad_LeftX, 1.0f), \
				\
				/* 视角左右移动 */ \
				FInputAxisKeyMapping("Turn Right / Left", EKeys::MouseX, 1.0f), \
				\
				/* 视角左右移动（手柄） */ \
				FInputAxisKeyMapping("Turn Right / Left", EKeys::Gamepad_RightX, 1.0f), \
				\
				/* 视角上下移动 */ \
				FInputAxisKeyMapping("Look Up / Down", EKeys::MouseY, -1.0f), \
				\
				/* 视角上下移动（手柄） */ \
				FInputAxisKeyMapping("Look Up / Down", EKeys::Gamepad_RightY, 1.0f), \
			}

#define DEFAULT_ACTION_MAPPINGS { \
				/* 跳跃*/ \
				FInputActionKeyMapping("Jump", EKeys::SpaceBar, false, false, false, false), \
				\
				/* 跳跃（手柄）*/ \
				FInputActionKeyMapping("Jump", EKeys::Gamepad_FaceButton_Bottom, false, false, false, false), \
				\
				/* 射击*/ \
				FInputActionKeyMapping("Shoot", EKeys::LeftMouseButton, false, false, false, false), \
				\
				/* 射击（手柄）*/ \
				FInputActionKeyMapping("Shoot", EKeys::Gamepad_RightTrigger, false, false, false, false), \
			}

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
	 * @brief 用户自定义的按键映射（轴映射）
	 */
	UPROPERTY(EditAnywhere, Category="KeyMappings")
	TArray<FInputAxisKeyMapping> CustomKeyAxisMappings;

	/**
	 * @brief 用户自定义的按键映射（按键映射）
	 */
	UPROPERTY(EditAnywhere, Category="KeyMappings")
	TArray<FInputActionKeyMapping> CustomKeyActionMappings;

	/**
	 * @brief 用于保存键位映射自定义设置
	 * @param bSaveDefault 是否为第一次保存
	 */
	void SaveCustomKeyMappingSettings(const bool bSaveDefault = false);

	/**
	 * @brief 用于读取用户的自定义键位映射（轴映射）
	 *        将读取的结果存放在CustomKeyAxisMappings中
	 * @return 返回CustomKeyAxisMappings
	 */
	TArray<FInputAxisKeyMapping> LoadCustomKeyAxisMappingSettings();

	/**
	 * @brief 用于读取用户的自定义键位映射（按键映射）
	 *        将读取的结果存放在CustomKeyActionMappings中
	 * @return 返回CustomKeyActionMappings
	 */
	TArray<FInputActionKeyMapping> LoadCustomKeyActionMappingSettings();
};
