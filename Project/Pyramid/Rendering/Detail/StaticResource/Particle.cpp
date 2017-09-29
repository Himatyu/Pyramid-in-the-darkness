/**
* @file		Particle.cpp
* @brief	パーティクルに必要なリソース
* @author	S.OIKAWA
* @date		2016.12.1
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Particle.h"
#include"../Rendering/Graphics.h"
#include"../Includer/RenderingIncluder.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Rendering;

namespace
{
	struct PARTICLE_FIXED
	{
		D3DXVECTOR3 Coord;
		DWORD       Index;
	};
}

namespace Pyramid
{
	namespace Rendering
	{
		using namespace HLRCommand;
		namespace Detail
		{
			namespace StaticResource
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				Particle::Particle()
				{
					CreateBuffer();
					CreatePipeline();
				}

				//-----------------------------------------------------------
				// CreatePipeline
				//-----------------------------------------------------------
				void Particle::CreatePipeline()
				{
					auto& line = m_SkeletonPipeline;
					line.StageingCommand<BeginScene>(Stage::BeginScene, &line);
					line.StageingCommand<SetDeclaration>(
						Stage::SetVertexDeclaration,
						m_Declaration, &line);
					line.StageingCommand<SetVertex>(Stage::SetVertex, &m_VertexBuffer, &line);
					line.StageingCommand<SetMaterial>(Stage::SetMaterial, nullptr, &line);
					line.StageingCommand<DrawPrimitive>(
						Stage::Draw,
						std::make_tuple(D3DPT_TRIANGLEFAN, 0, m_PolygenCount), &line);
					line.StageingCommand<RiseMateral>(Stage::RiseMateral, nullptr, &line);
					line.StageingCommand<EndScene>(Stage::EndScene, &line);
					line.CommitCommandImmediate();
				}

				//-----------------------------------------------------------
				// CreateBuffer
				//-----------------------------------------------------------
				void Particle::CreateBuffer()
				{
					auto pDevice = Graphics::Instantiate().Device;

					D3DVERTEXELEMENT9 vertexElem[] = {
						{ 0, 0              , D3DDECLTYPE_FLOAT3  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 }, // 頂点座標
						{ 0, sizeof(D3DXVECTOR3) , D3DDECLTYPE_UBYTE4  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_BLENDINDICES, 0 }, // 頂点インデックス		
						D3DDECL_END()
					};

					pDevice->CreateVertexDeclaration(vertexElem, &m_Declaration);

					pDevice->CreateVertexBuffer(
						4 * sizeof(PARTICLE_FIXED),
						D3DUSAGE_WRITEONLY,
						0,
						D3DPOOL_MANAGED,
						&m_VertexBuffer.Data,
						NULL);

					m_VertexBuffer.Count = 4;
					m_VertexBuffer.TypeSize = sizeof(PARTICLE_FIXED);

					PARTICLE_FIXED* vertexs;
					m_VertexBuffer.Data->Lock(0, 0, (void**)&vertexs, 0);

					vertexs[0].Coord = D3DXVECTOR3(-0.5, -0.5, 0);
					vertexs[1].Coord = D3DXVECTOR3(-0.5, 0.5, 0);
					vertexs[2].Coord = D3DXVECTOR3(0.5, 0.5, 0);
					vertexs[3].Coord = D3DXVECTOR3(0.5, -0.5, 0);

					//(0,0) 1------2 (1,0)
					//		|      |
					//		|      |
					//(0,1) 0------3 (1,1)

					//0,0,1,1
					// uv[8]{ 0,1,0,0, 1,0, 1,1};

					//Xを指定してYを内部演算
					vertexs[0].Index = 0;
					vertexs[1].Index = 1;
					vertexs[2].Index = 2;
					vertexs[3].Index = 3;

					m_VertexBuffer.Data->Unlock();

				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


