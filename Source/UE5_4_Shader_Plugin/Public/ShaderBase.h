#pragma once

#include "CoreMinimal.h"

class FRHICommandListImmediate;

class FShaderParametersBase
{
};

class UE5_4_SHADER_PLUGIN_API FShaderBase
{

public:
	// Call this when you want to hook onto the renderer and start drawing. The shader will be executed once per frame.
	void BeginRendering();

	// When you are done, call this to stop drawing.
	void EndRendering();

	 //Call this whenever you have new parameters to share. You could set this up to update different sets of properties at
	 //different intervals to save on locking and GPU transfer time.
	void UpdateParameters(FShaderParametersBase& params);

public:
	virtual void SetupShader();
	virtual void RunShader();

public:

	FShaderBase()
	{
		//const FName RendererModuleName("Renderer");
		//m_rendererModuleRef = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);
	}

private:
	void PostResolveSceneColor(FRDGBuilder& builder, const FSceneTextures& SceneTexture);
	void Draw();

protected:
	bool m_bShaderReady = false;
	bool m_bParametersValid = false;
	FDelegateHandle m_onPostResolvedSceneColorHandle;
	FCriticalSection m_renderEveryFrameLock;

protected:
	IRendererModule * m_rendererModuleRef;
	FRHICommandListImmediate * m_commandList;
	FShaderParametersBase * m_shaderParameters;
};
