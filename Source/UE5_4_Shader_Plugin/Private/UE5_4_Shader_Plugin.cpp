// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_4_Shader_Plugin.h"
#include "Interfaces/IPluginManager.h"

//#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FUE5_4_Shader_PluginModule"

void FUE5_4_Shader_PluginModule::StartupModule()
{
	// Maps the virtual shader source directory to the shader directory in our project
	const FString pluginBaseDir = IPluginManager::Get().FindPlugin(TEXT("UE5_4_Shader_Plugin"))->GetBaseDir();
	const FString pluginShaderDir = FPaths::Combine(pluginBaseDir, TEXT("Shaders/Private"));
	const FString virtualShaderDir = TEXT("/Plugin/UE5_4_Shader_Plugin");
	AddShaderSourceDirectoryMapping(virtualShaderDir, pluginShaderDir);
}

void FUE5_4_Shader_PluginModule::ShutdownModule()
{
	// Cleanup the virtual source directory mapping.
	ResetAllShaderSourceDirectoryMappings();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUE5_4_Shader_PluginModule, UE5_4_Shader_Plugin)