/**
* @file		ParticleMateral.h
* @brief	パーティクルマテリアル
* @author	S.OIKAWA
* @date		2016.09.12
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "ParticleMaterial.h"
#include"../Rendering/Graphics.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			using namespace Blueprint;
			using namespace std;
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ParticleMateral::ParticleMateral():
				m_Shader(this)
			{
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			ParticleMateral::~ParticleMateral()
			{
			}

			//-----------------------------------------------------------
			// SetMateral
			//-----------------------------------------------------------
			void ParticleMateral::SetMateral()
			{
				m_Shader.SetData();
				m_Shader.SetMatrix();
				m_Shader.Begin();
			}

			//-----------------------------------------------------------
			// RiseMateral
			//-----------------------------------------------------------
			void ParticleMateral::RiseMateral()
			{
				m_Shader.Eed();
			}

			//-----------------------------------------------------------
			// SetMatrix
			//-----------------------------------------------------------
			void ParticleMateral::SetMatrix(D3DXMATRIX & _mat)
			{
				m_Shader.pMatrix = &_mat;
			}
		}
	}
}