// Copyright (c) XuZirui 2022

using UnrealBuildTool;

public class RuntimeTest : ModuleRules
{
	public RuntimeTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
			{ "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "Strike" });
	}
}