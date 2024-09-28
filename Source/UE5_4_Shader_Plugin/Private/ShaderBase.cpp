#include "ShaderBase.h"
#include "RHICommandList.h"

void FShaderBase::BeginRendering()
{
	if (m_onPostResolvedSceneColorHandle.IsValid())
	{
		return;
	}

	m_bParametersValid = false;
	if (m_rendererModuleRef)
	{
		m_onPostResolvedSceneColorHandle = m_rendererModuleRef->GetResolvedSceneColorCallbacks().AddRaw(this, &FShaderBase::PostResolveSceneColor);
	}
}

void FShaderBase::EndRendering()
{
	if (!m_onPostResolvedSceneColorHandle.IsValid())
	{
		return;
	}


	if (m_rendererModuleRef)
	{
		m_rendererModuleRef->GetResolvedSceneColorCallbacks().Remove(m_onPostResolvedSceneColorHandle);
	}

	m_onPostResolvedSceneColorHandle.Reset();
}

void FShaderBase::UpdateParameters(FShaderParametersBase& params)
{
	m_renderEveryFrameLock.Lock();
	m_shaderParameters = &params;
	m_bParametersValid = true;
	m_renderEveryFrameLock.Unlock();
}

void FShaderBase::PostResolveSceneColor(FRDGBuilder& builder, const FSceneTextures& SceneTexture)
{
	if (!m_bParametersValid)
	{
		return;
	}

	Draw();
}

void FShaderBase::Draw()
{
	SetupShader();
	RunShader();
}

void FShaderBase::SetupShader()
{
	check(IsInRenderingThread());
	m_commandList = &GRHICommandList.GetImmediateCommandList();
	QUICK_SCOPE_CYCLE_COUNTER(STAT_ShaderPlugin_Render); // Used to gather CPU profiling data for the UE4 session frontend
	SCOPED_DRAW_EVENT(*m_commandList, ShaderPlugin_Render); // Used to profile GPU activity and add metadata to be consumed by for example RenderDoc
}

void FShaderBase::RunShader()
{
}

