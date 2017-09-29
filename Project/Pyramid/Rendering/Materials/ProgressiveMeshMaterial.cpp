/**
* @file		ProgressiveMeshMaterial.cpp
* @brief	低レベルモデル用のマテリアル
* @author	S.OIKAWA
* @date		2017.02.05
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ProgressiveMeshMaterial.h"
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
			ProgressiveMeshMaterial::ProgressiveMeshMaterial():
				m_Shader(this)
			{
			}
			//-----------------------------------------------------------
			// SetMateral
			//-----------------------------------------------------------
			void ProgressiveMeshMaterial::SetMateral()
			{
				m_Shader.SetData();
				m_Shader.SetMatrix();
				m_Shader.Begin();
			}

			//-----------------------------------------------------------
			// RiseMateral
			//-----------------------------------------------------------
			void ProgressiveMeshMaterial::RiseMateral()
			{
				m_Shader.Eed();
			}

			//-----------------------------------------------------------
			// SetMatrix
			//-----------------------------------------------------------
			void ProgressiveMeshMaterial::SetMatrix(D3DXMATRIX & _mat)
			{
				m_Shader.pMatrix = &_mat;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------