// Copyright (c) XuZirui 2022


#include "Player/FPSPlayerController.h"

#include "FPSGameInstance.h"
#include "GameFramework/InputSettings.h"

AFPSPlayerController::AFPSPlayerController()
{
}

void AFPSPlayerController::SetupInputComponent()
{
	auto a = Cast<UFPSGameInstance>(GetGameInstance());
	// 从设置中心读取键位映射
	for (auto InputAxisKeyMapping : a->CustomSettingSave->LoadCustomKeyMappingSettings())
	{
		// 构建键位映射
		UInputSettings::GetInputSettings()->AddAxisMapping(InputAxisKeyMapping, true);
	}
}
