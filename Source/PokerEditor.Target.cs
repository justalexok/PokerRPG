// Copyright Alex Goulder

using UnrealBuildTool;
using System.Collections.Generic;

public class PokerEditorTarget : TargetRules
{
	public PokerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Poker" } );
	}
}
