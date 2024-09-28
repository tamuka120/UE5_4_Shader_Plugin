// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5_4_Shader_Plugin : ModuleRules
{
	public UE5_4_Shader_Plugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"RHI",        // Rendering Hardware Interface. It’s the C++ interface that UE uses to communicate with Direct3D, OpenGL, etc.
                "RenderCore", // (Formerly ShaderCore) Needed for AddShaderSourceDirectoryMapping & ResetAllShaderSourceDirectoryMappings
				"Projects",   // Needed for IPluginManager
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
