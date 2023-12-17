// Copyright Alex Goulder

using UnrealBuildTool;
using System.Collections.Generic;

public class PokerTarget : TargetRules
{
	public PokerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Poker" } );
	}
}
