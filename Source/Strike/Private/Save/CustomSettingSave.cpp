// Copyright (c) XuZirui 2022

#include "Save/CustomSettingSave.h"

#include "Kismet/GameplayStatics.h"

UCustomSettingSave::UCustomSettingSave()
{
}

void UCustomSettingSave::SaveCustomKeyMappingSettings(const bool bSaveDefault)
{
	if (UCustomSettingSave* SaveGameInstance = Cast<UCustomSettingSave>(
		UGameplayStatics::CreateSaveGameObject(StaticClass())))
	{
		if (bSaveDefault)
		{
			// 第一次保存设置
			CustomKeyAxisMappings = DEFAULT_AXIS_MAPPINGS;

			CustomKeyActionMappings = DEFAULT_ACTION_MAPPINGS;
		}
		// 设置保存对象上的数据
		SaveGameInstance->CustomKeyAxisMappings = CustomKeyAxisMappings;
		SaveGameInstance->CustomKeyActionMappings = CustomKeyActionMappings;

		// 即时保存游戏。
		UGameplayStatics::SaveGameToSlot(SaveGameInstance, KEY_MAPPING_SAVE_NAME, 0);
		// 调试用
		UE_LOG(LogTemp, Display, TEXT("Saved Custom Key Mapping Settings"));
	}
}

TArray<FInputAxisKeyMapping> UCustomSettingSave::LoadCustomKeyAxisMappingSettings()
{
	if (!UGameplayStatics::DoesSaveGameExist(KEY_MAPPING_SAVE_NAME, 0))
	{
		// 如果还没有存储文件就创建一个
		SaveCustomKeyMappingSettings(true);
	}
	if (UCustomSettingSave* LoadedSaveInstance = Cast<UCustomSettingSave>(
		UGameplayStatics::LoadGameFromSlot(KEY_MAPPING_SAVE_NAME, 0)))
	{
		// 读取出存储文件中的设置
		CustomKeyAxisMappings = LoadedSaveInstance->CustomKeyAxisMappings;

		// 调试用
		UE_LOG(LogTemp, Display, TEXT("Loaded Custom Key Axis Mapping Settings"));
	}
	return CustomKeyAxisMappings;
}

TArray<FInputActionKeyMapping> UCustomSettingSave::LoadCustomKeyActionMappingSettings()
{
	if (!UGameplayStatics::DoesSaveGameExist(KEY_MAPPING_SAVE_NAME, 0))
	{
		// 如果还没有存储文件就创建一个
		SaveCustomKeyMappingSettings(true);
	}
	if (UCustomSettingSave* LoadedSaveInstance = Cast<UCustomSettingSave>(
		UGameplayStatics::LoadGameFromSlot(KEY_MAPPING_SAVE_NAME, 0)))
	{
		// 读取出存储文件的设置
		CustomKeyActionMappings = LoadedSaveInstance->CustomKeyActionMappings;

		// 调试用
		UE_LOG(LogTemp, Display, TEXT("Loaded Custom Key Axis Mapping Settings"));
	}
	return CustomKeyActionMappings;
}
