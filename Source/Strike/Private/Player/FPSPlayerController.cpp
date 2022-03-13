// Copyright (c) XuZirui 2022


#include "Player/FPSPlayerController.h"

#include "FPSGameInstance.h"
#include "GameFramework/InputSettings.h"

AFPSPlayerController::AFPSPlayerController()
{
}

void AFPSPlayerController::SetupInputComponent()
{
	// 从设置中心读取键位映射（轴映射）
	for (auto InputAxisKeyMapping : Cast<UFPSGameInstance>(GetGameInstance())->CustomSettingSave->
	                                                                           LoadCustomKeyAxisMappingSettings())
	{
		// 构建键位映射
		UInputSettings::GetInputSettings()->AddAxisMapping(InputAxisKeyMapping, true);
	}
	// 从设置中心读取键位映射（按键映射）
	for (auto InputActionKeyMapping : Cast<UFPSGameInstance>(GetGameInstance())->CustomSettingSave->
	                                                                           LoadCustomKeyActionMappingSettings())
	{
		// 构建键位映射
		UInputSettings::GetInputSettings()->AddActionMapping(InputActionKeyMapping, true);
	}
}
