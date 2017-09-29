/**
* @brief	静的な矩形のレンダリングリソース
* @author	S.OIKAWA
* @date		2016.12.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Quad.h"
#include"../../Constant.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
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
		namespace Detail
		{
			namespace StaticResource
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				Quad::Quad() :
					m_PolygenCount(Constant::StaticQuadPolygenCount)
				{
				}

				//-----------------------------------------------------------
				// dtor
				//-----------------------------------------------------------
				Quad::~Quad()
				{
					m_VertexBuffer.Delete(m_VertexBuffer.Data);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------