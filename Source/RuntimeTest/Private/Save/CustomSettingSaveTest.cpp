// Copyright (c) XuZirui 2022

#include "Kismet/GameplayStatics.h"
#include "Save/CustomSettingSave.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(CustomSettingSaveTest, "Strike.RuntimeTest.Private.Save.CustomSettingSaveTest",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool CustomSettingSaveTest::RunTest(const FString& Parameters)
{
	// 创建测试对象
	UCustomSettingSave* CustomSettingSave = NewObject<UCustomSettingSave>();

	// 删除已有的文件，便于测试
	if (UGameplayStatics::DoesSaveGameExist(KEY_MAPPING_SAVE_NAME, 0))
	{
		UGameplayStatics::DeleteGameInSlot(KEY_MAPPING_SAVE_NAME, 0);
	}

	TestEqual(TEXT("LoadCustomKeyAxisMappingSettings must return correct TArray<FInputAxisKeyMapping>"),
	          CustomSettingSave->LoadCustomKeyAxisMappingSettings(), DEFAULT_AXIS_MAPPINGS);

	TestEqual(TEXT("LoadCustomKeyActionMappinSettings must return correct TArray<FInputActionKeyMapping>"),
		      CustomSettingSave->LoadCustomKeyActionMappingSettings(), DEFAULT_ACTION_MAPPINGS);

	return true;
}
