// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StrikeEditorTarget : TargetRules
{
	public StrikeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new[] { "Strike", "RuntimeTest" });
	}
}