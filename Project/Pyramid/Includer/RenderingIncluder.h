/**
* @file		RenderingIncluder.h
* @brief	レンダリングのインクルーダ
* @author	S.OIKAWA
* @date		2017.01.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Rendering/Buffer.h"
#include"../Rendering/CameraLayer.h"
#include"../Rendering/Color.h"
#include"../Rendering/Constant.h"
#include"../Rendering/Graphics.h"
#include"../Rendering/RenderProvider.h"
#include"../Rendering/RendringPriority.h"
#include"../Rendering/Viewer.h"

//-----------------------------------------------------------
// ComponentRender
//-----------------------------------------------------------
#include"../Rendering/ComponentRender/AABBRender.h"
#include"../Rendering/ComponentRender/FbxRender.h"
#include"../Rendering/ComponentRender/PanelRender.h"
#include"../Rendering/ComponentRender/ParticleRender.h"

//-----------------------------------------------------------
// Detail
//-----------------------------------------------------------
#include"../Rendering/Detail/Frustum.h"
#include"../Rendering/Detail/IRenderable.h"
#include"../Rendering/Detail/LightingPublisher.h"
#include"../Rendering/Detail/OptimizationRender.h"
#include"../Rendering/Detail/StaticResource/Panel.h"
#include"../Rendering/Detail/StaticResource/Particle.h"
#include"../Rendering/Detail/StaticResource/Quad.h"
#include"../Rendering/Detail/Optimize/CommandFinalizer.h"
#include"../Rendering/Detail/Optimize/ContinuityOptimizate.h"
#include"../Rendering/Detail/Optimize/JudgmentSameSpaceOfFrustum.h"
#include"../Rendering/Detail/Optimize/LODSwitcher.h"
#include"../Rendering/Detail/Optimize/MLRC.h"
#include"../Rendering/Detail/Optimize/MLRCPublisher.h"
#include"../Rendering/Detail/Optimize/VisibleDeterminer.h"

//-----------------------------------------------------------
// HLRCommand
//-----------------------------------------------------------
#include"../Rendering/HLRCommand/HLRCPipelineStage.h"

#include"../Rendering/HLRCommand/SetDeclaration.h"
#include"../Rendering/HLRCommand/SetFVF.h"
#include"../Rendering/HLRCommand/SetIndex.h"
#include"../Rendering/HLRCommand/SetVertex.h"
#include"../Rendering/HLRCommand/SetMaterial.h"
#include"../Rendering/HLRCommand/RiseMateral.h"
#include"../Rendering/HLRCommand/DrawIndexedPrimitive.h"
#include"../Rendering/HLRCommand/DrawPrimitive.h"
#include"../Rendering/HLRCommand/BeginScene.h"
#include"../Rendering/HLRCommand/EndScene.h"

#include"../Rendering/HLRCommand/Default/BeginScene.h"
#include"../Rendering/HLRCommand/Default/EndScene.h"
#include"../Rendering/HLRCommand/Default/SetMaterial.h"
#include"../Rendering/HLRCommand/Default/RiseMateral.h"
#include"../Rendering/HLRCommand/Default/SetIndex.h"
#include"../Rendering/HLRCommand/Default/SetVertex.h"
#include"../Rendering/HLRCommand/Default/SetVertexDeclaration.h"
#include"../Rendering/HLRCommand/Default/Draw.h"

//-----------------------------------------------------------
// Materials
//-----------------------------------------------------------
#include"../Rendering/Materials/ColorChannel.h"
#include"../Rendering/Materials/Material.h"
#include"../Rendering/Materials/MeshMaterial.h"
#include"../Rendering/Materials/PanelMaterial.h"
#include"../Rendering/Materials/ParticleMaterial.h"
#include"../Rendering/Materials/ProgressiveMeshMaterial.h"

//-----------------------------------------------------------
// Shaders
//-----------------------------------------------------------
#include"../Rendering/Shaders/MeshShader.h"
#include"../Rendering/Shaders/PanelShader.h"
#include"../Rendering/Shaders/ParticleShader.h"
#include"../Rendering/Shaders/ProgressiveMeshShader.h"
#include"../Rendering/Shaders/Shader.h"

//-----------------------------------------------------------
// Target
//-----------------------------------------------------------
#include"../Rendering/Target/RenderingTexture.h"
#include"../Rendering/Target/RenderTarget.h"
#include"../Rendering/Target/Screen.h"

#pragma endregion
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------