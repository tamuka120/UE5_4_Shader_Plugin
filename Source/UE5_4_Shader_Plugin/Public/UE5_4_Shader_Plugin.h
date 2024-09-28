// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "ShaderBase.h"

class UE5_4_SHADER_PLUGIN_API FUE5_4_Shader_PluginModule : public IModuleInterface
{
public:

	/**IModuleInterface implementation */

	/** 
		This code will execute after your module is loaded into memory. The exact timing is specified in the .uplugin file per-module
	    by the LoadingPhase. This determines when the module is loaded during engine startup.

	    Default: During engine init, after game modules are loaded.
	    PostEngineInit : After the engine has been initialized.
	    https://github.com/ibbles/LearningUnrealEngine
	*/
	virtual void StartupModule() override;


	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	virtual void ShutdownModule() override;
};
