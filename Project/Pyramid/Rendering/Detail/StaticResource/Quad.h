/**
* @file		Quad.h
* @brief	静的な矩形のレンダリングリソース
* @author	S.OIKAWA
* @date		2016.12.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3dx9.h>
#include"../Rendering/Buffer.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace StaticResource
			{
				/// <summary>
				/// 静的な矩形のレンダリングリソース
				/// </summary>
				class Quad
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Quad();
					~Quad();

					Quad(const Quad&) = default;
					Quad(Quad&&) = default;

					Quad& operator=(const Quad&) = default;
					Quad& operator=(Quad&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
#pragma endregion
				public:
#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_REF_R_ONLY(m_VertexBuffer, VertexBuffer, DirectXVertexBuffer);
					PROPERTY_REF_R_ONLY(m_Declaration, Declaration, LPDIRECT3DVERTEXDECLARATION9);
					PROPERTY_REF_R_ONLY(m_PolygenCount, PolygenCount, UINT);
#pragma endregion
				protected:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					DirectXVertexBuffer								m_VertexBuffer;
					LPDIRECT3DVERTEXDECLARATION9					m_Declaration;
					UINT											m_PolygenCount;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------