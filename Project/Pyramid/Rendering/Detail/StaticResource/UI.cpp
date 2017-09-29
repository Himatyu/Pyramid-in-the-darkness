/**
* @file		UI.cpp
* @brief	UI���\�����钸�_����ێ�
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UI.h"
#include"../Rendering/Graphics.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace
{
	struct UI_FIXED
	{
		D3DXVECTOR3 Coord;
		DWORD       Index;
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
				UI::UI()
				{
					auto pDevice = Graphics::Instantiate().Device;

					D3DVERTEXELEMENT9 vertexElem[] = {
						{ 0, 0              , D3DDECLTYPE_FLOAT3  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 }, // ���_���W
						{ 0, sizeof(D3DXVECTOR3) , D3DDECLTYPE_UBYTE4  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_BLENDINDICES, 0 }, // ���_�C���f�b�N�X		
						D3DDECL_END()
					};

					pDevice->CreateVertexDeclaration(vertexElem, &m_Declaration);

					pDevice->CreateVertexBuffer(
						4 * sizeof(UI_FIXED),
						D3DUSAGE_WRITEONLY,
						0,
						D3DPOOL_MANAGED,
						&m_VertexBuffer.Data,
						NULL);

					m_VertexBuffer.Count = 4;
					m_VertexBuffer.TypeSize = sizeof(UI_FIXED);

					UI_FIXED* vertexs;
					m_VertexBuffer.Data->Lock(0, 0, (void**)&vertexs, 0);

					vertexs[0].Coord = D3DXVECTOR3(0, 0, 0);
					vertexs[1].Coord = D3DXVECTOR3(1, 0, 0);
					vertexs[2].Coord = D3DXVECTOR3(0, 1, 0);
					vertexs[3].Coord = D3DXVECTOR3(1, 1, 0);

					//(0,0) 2------3 (1,0)
					//		|      |
					//		|      |
					//(0,1) 0------1 (1,1)

					//X���w�肵��Y��������Z
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