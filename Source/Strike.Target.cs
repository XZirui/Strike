// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StrikeTarget : TargetRules
{
	public StrikeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("Strike");
	}
}