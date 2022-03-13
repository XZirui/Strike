// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Strike : ModuleRules
{
	public Strike(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
			{ "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}