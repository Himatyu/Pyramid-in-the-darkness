/**
* @file		CacheableTransform.cpp
* @brief	コリジョンに使用するトランスフォームをキャッシュする
* @author	S.OIKAWA
* @date		2017.05.03
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"CacheableTransform.h"
#include"../Components/Transform.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			CacheableTransform::CacheableTransform(
				Components::Transform * _pTransform)
			{
				m_Position = _pTransform->Position;
				m_Rotate = _pTransform->Rotation;
				m_Scale = _pTransform->Scale;
			}


			//-----------------------------------------------------------
			// =
			//-----------------------------------------------------------
			CacheableTransform &
			CacheableTransform::operator=(
				Common::Sp<Components::Transform>& _spTransform)
			{
				m_Position = _spTransform->Position;
				m_Rotate = _spTransform->Rotation;
				m_Scale = _spTransform->Scale;

				return *this;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------