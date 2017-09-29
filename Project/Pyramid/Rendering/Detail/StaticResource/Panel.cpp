/**
* @file		PanelShader.cpp
* @brief	パネルを構成する頂点情報を保持
* @author	S.OIKAWA
* @date		2016.12.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Panel.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace
{
	struct PANEL_FIXED
	{
		D3DXVECTOR3 Coord;
		D3DXVECTOR2 UV;
	};
}
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace StaticResource
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				Panel::Panel()
				{
					CreateBuffer();
				}

				//-----------------------------------------------------------
				// CreateBuffer
				//-----------------------------------------------------------
				void Panel::CreateBuffer()
				{
					auto pDevice = Graphics::Instantiate().Device;

					D3DVERTEXELEMENT9 vertexElem[] = {
						{ 0, 0              , D3DDECLTYPE_FLOAT3  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 }, // 頂点座標
						{ 0, sizeof(D3DXVECTOR3) , D3DDECLTYPE_FLOAT2  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 }, // テクスチャ		
						D3DDECL_END()
					};

					pDevice->CreateVertexDeclaration(vertexElem, &m_Declaration);

					pDevice->CreateVertexBuffer(
						4 * sizeof(PANEL_FIXED),
						D3DUSAGE_WRITEONLY,
						0,
						D3DPOOL_MANAGED,
						&m_VertexBuffer.Data,
						NULL);

					m_VertexBuffer.Count = 4;
					m_VertexBuffer.TypeSize = sizeof(PANEL_FIXED);

					PANEL_FIXED* vertexs;
					m_VertexBuffer.Data->Lock(0, 0, (void**)&vertexs, 0);

					vertexs[0].Coord = D3DXVECTOR3(-0.5, -0.5, 0);
					vertexs[1].Coord = D3DXVECTOR3(-0.5, 0.5, 0);
					vertexs[2].Coord = D3DXVECTOR3(0.5, 0.5, 0);
					vertexs[3].Coord = D3DXVECTOR3(0.5, -0.5, 0);

					//(0,0) 1------2 (1,0)
					//		|      |
					//		|      |
					//(0,1) 0------3 (1,1)

					vertexs[0].UV = D3DXVECTOR2(0, 1);
					vertexs[1].UV = D3DXVECTOR2(0, 0);
					vertexs[2].UV = D3DXVECTOR2(1, 0);
					vertexs[3].UV = D3DXVECTOR2(1, 1);

					m_VertexBuffer.Data->Unlock();

				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------