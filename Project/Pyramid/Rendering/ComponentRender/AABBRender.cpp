/**
* @file		AABBRender.cpp
* @brief	デバック用のAABBをレンダリングする
* @author	S.OIKAWA
* @date		2017.02.06
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"AABBRender.h"
#include"../Components/Transform.h"
#include"../Rendering/HLRCommand/HLRCommandPipeline.h"
#include"../Rendering/HLRCommand/Default/StaticDefaultCommand.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace
{
	struct AABB_FIXED
	{
		D3DXVECTOR3 Coord;
	};
}

using namespace Pyramid::Rendering::HLRCommand;
using namespace Pyramid::Rendering::Detail::Optimize;
namespace Pyramid
{
	namespace Rendering
	{
		namespace ComponentRender
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			AABBRender::AABBRender() :
				m_Pipeline(),
				OptimizationRender(m_Pipeline),
				Optimizer
				(
				{ m_Pipeline,m_RenderVolume }, 
				{ m_RenderVolume,this ,0 }
				)
			{
			}

			//-----------------------------------------------------------
			// Init
			//-----------------------------------------------------------
			void AABBRender::Init(
				Common::WorldVolume& _vol, 
				Common::Sp<Components::Transform> _spTransform,
				UINT _priority)
			{
				WorldObjectRender::Init(_vol.Volume, &_spTransform->Position);
				SetMLRC(_priority);				

				auto pDevice = Graphics::Instantiate().Device;

				D3DVERTEXELEMENT9 vertexElem[] = {
					{ 0, 0              ,
					D3DDECLTYPE_FLOAT3  , 
					D3DDECLMETHOD_DEFAULT, 
					D3DDECLUSAGE_POSITION, 
					0 }, // 頂点座標
					D3DDECL_END()
				};

				pDevice->CreateVertexDeclaration(vertexElem, &m_Declaration);

				pDevice->CreateVertexBuffer(
					16 * sizeof(AABB_FIXED),
					D3DUSAGE_WRITEONLY,
					0,
					D3DPOOL_MANAGED,
					&m_VertexBuffer.Data,
					NULL);

				m_VertexBuffer.Count = 15;
				m_VertexBuffer.TypeSize = sizeof(AABB_FIXED);

				UpdataBuffer();
				
				m_Pipeline.StageingCommand<BeginScene>(Stage::BeginScene, &m_Pipeline);
				m_Pipeline.StageingCommand<SetDeclaration>(Stage::SetVertexDeclaration, m_Declaration, &m_Pipeline);
				m_Pipeline.StageingCommand<SetVertex>(Stage::SetVertex, &m_VertexBuffer, &m_Pipeline);
				m_Pipeline.StageingCommand<DrawPrimitive>(Stage::Draw, std::make_tuple(
					D3DPT_LINESTRIP,
					0,
					m_VertexBuffer.Count), &m_Pipeline);
				m_Pipeline.StageingCommand<EndScene>(Stage::EndScene, &m_Pipeline);

				m_Pipeline.CommitCommandImmediate();

				CallInit();
			}


			//-----------------------------------------------------------
			// OptimizerUpdate
			//-----------------------------------------------------------
			void AABBRender::OptimizerUpdate()
			{
				CallUpdate();
			}

			//-----------------------------------------------------------
			// PrepareToOptimize
			//-----------------------------------------------------------
			void AABBRender::PrepareToOptimize()
			{
			}

			//-----------------------------------------------------------
			// Optimize
			//-----------------------------------------------------------
			void AABBRender::Optimize(const Detail::Optimize::Context & _context)
			{
				CallOptimize(_context);
			}

			//-----------------------------------------------------------
			// PrepareToRendering
			//-----------------------------------------------------------
			void AABBRender::PrepareToRendering()
			{
				D3DXMATRIX mat;
				D3DXMatrixIdentity(&mat);
				auto& device = Rendering::Graphics::Instantiate().Device;
				device->SetTransform(D3DTS_WORLD, &mat);
				UpdataBuffer();
			}
			//-----------------------------------------------------------
			// Rendering
			//-----------------------------------------------------------
			void AABBRender::Rendering()
			{
				Optimizated.Run();
			}

			//-----------------------------------------------------------
			// UpdataBuffer
			//-----------------------------------------------------------
			void AABBRender::UpdataBuffer()
			{
				auto worldVolume = m_RenderVolume.CalculatWorldVolume();

				AABB_FIXED* vertexs;
				m_VertexBuffer.Data->Lock(0, 0, (void**)&vertexs, 0);

				vertexs[0].Coord = D3DXVECTOR3(worldVolume.Min.X, worldVolume.Max.Y, worldVolume.Min.Z);
				vertexs[1].Coord = D3DXVECTOR3(worldVolume.Max.X, worldVolume.Max.Y, worldVolume.Min.Z);
				vertexs[2].Coord = D3DXVECTOR3(worldVolume.Max.X, worldVolume.Min.Y, worldVolume.Min.Z);
				vertexs[3].Coord = worldVolume.Min.ToDirectX();
				vertexs[4].Coord = D3DXVECTOR3(worldVolume.Min.X, worldVolume.Max.Y, worldVolume.Min.Z);

				vertexs[5].Coord = D3DXVECTOR3(worldVolume.Min.X, worldVolume.Max.Y, worldVolume.Max.Z);
				vertexs[6].Coord = D3DXVECTOR3(worldVolume.Min.X, worldVolume.Min.Y, worldVolume.Max.Z);
				vertexs[7].Coord = D3DXVECTOR3(worldVolume.Max.X, worldVolume.Min.Y, worldVolume.Max.Z);
				vertexs[8].Coord = worldVolume.Max.ToDirectX();
				vertexs[9].Coord = D3DXVECTOR3(worldVolume.Min.X, worldVolume.Max.Y, worldVolume.Max.Z);

				vertexs[10].Coord = D3DXVECTOR3(worldVolume.Min.X, worldVolume.Min.Y, worldVolume.Max.Z);
				vertexs[11].Coord = worldVolume.Min.ToDirectX();

				vertexs[12].Coord = D3DXVECTOR3(worldVolume.Max.X, worldVolume.Min.Y, worldVolume.Min.Z);
				vertexs[13].Coord = D3DXVECTOR3(worldVolume.Max.X, worldVolume.Min.Y, worldVolume.Max.Z);

				vertexs[14].Coord = D3DXVECTOR3(worldVolume.Max.X, worldVolume.Max.Y, worldVolume.Max.Z);
				vertexs[15].Coord = D3DXVECTOR3(worldVolume.Max.X, worldVolume.Max.Y, worldVolume.Min.Z);

				m_VertexBuffer.Data->Unlock();
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------