/**
* @file		UIMaterial.cpp
* @brief	UIマテリアル
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UIMaterial.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			UIMaterial::UIMaterial(::std::string _path):
				m_Shader(this,_path),
				m_pArrayUV{0,0,1,1,}
			{
			}
			//-----------------------------------------------------------
			// SetMateral
			//-----------------------------------------------------------
			void UIMaterial::SetMateral()
			{
				m_Shader.SetMatrix();
				m_Shader.SetData();
				m_Shader.Begin();
			}

			//-----------------------------------------------------------
			// RiseMateral
			//-----------------------------------------------------------
			void UIMaterial::RiseMateral()
			{
				m_Shader.Eed();
			}

			//-----------------------------------------------------------
			// SetMatrix
			//-----------------------------------------------------------
			void UIMaterial::SetMatrix(D3DXMATRIX & _mat)
			{
				m_Shader.pMatrix = &_mat;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------