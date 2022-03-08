// Copyright (c) XuZirui 2022

#include "Save/CustomSettingSave.h"

#include "Kismet/GameplayStatics.h"

UCustomSettingSave::UCustomSettingSave()
{
}

void UCustomSettingSave::SaveCustomKeyMappingSettings(const bool bSaveDefault)
{
	if (UCustomSettingSave* SaveGameInstance = Cast<UCustomSettingSave>(UGameplayStatics::CreateSaveGameObject(UCustomSettingSave::StaticClass())))
	{
		if (bSaveDefault)
		{
			// 第一次保存设置
			CustomKeyMappings = {
				// 前后移动
				FInputAxisKeyMapping("Move Forward / Backward", EKeys::W, 1.0f),
				FInputAxisKeyMapping("Move Forward / Backward", EKeys::S, -1.0f),

				// 前后移动（手柄）
				FInputAxisKeyMapping("Move Forward / Backward", EKeys::Gamepad_LeftY, 1.0f),

				// 左右移动
				FInputAxisKeyMapping("Move Right / Left", EKeys::D, 1.0f),
				FInputAxisKeyMapping("Move Right / Left", EKeys::A, -1.0f),

				// 左右移动（手柄）
				FInputAxisKeyMapping("Move Right / Left", EKeys::Gamepad_LeftX, 1.0f),

				// 视角左右移动
				FInputAxisKeyMapping("Turn Right / Left", EKeys::MouseX, 1.0f),

				// 视角左右移动（手柄）
				FInputAxisKeyMapping("Turn Right / Left", EKeys::Gamepad_RightX, 1.0f),

				// 视角上下移动
				FInputAxisKeyMapping("Look Up / Down", EKeys::MouseY, -1.0f),

				// 视角上下移动（手柄）
				FInputAxisKeyMapping("Look Up / Down", EKeys::Gamepad_RightY, 1.0f)
			};
		}
		// 设置保存对象上的数据
		SaveGameInstance->CustomKeyMappings = CustomKeyMappings;

		// 即时保存游戏。
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, "KeyMappingSave", 0);
		// 调试用
		UE_LOG(LogTemp, Display, TEXT("Saved Custom Key Mapping Settings"));
	}
}

TArray<FInputAxisKeyMapping> UCustomSettingSave::LoadCustomKeyMappingSettings()
{
	if (!UGameplayStatics::DoesSaveGameExist(KEY_MAPPING_SAVE_NAME, 0))
	{
	    // 如果还没有存储文件就创建一个
		SaveCustomKeyMappingSettings(true);
	}
	if (UCustomSettingSave* LoadedSaveInstance = Cast<UCustomSettingSave>(UGameplayStatics::LoadGameFromSlot(KEY_MAPPING_SAVE_NAME, 0)))
	{
	    // 读取出存储文件中的设置
		CustomKeyMappings = LoadedSaveInstance->CustomKeyMappings;

		// 调试用
		UE_LOG(LogTemp, Display, TEXT("Loaded Custom Key Mapping Settings"));
	}
	return CustomKeyMappings;
}
