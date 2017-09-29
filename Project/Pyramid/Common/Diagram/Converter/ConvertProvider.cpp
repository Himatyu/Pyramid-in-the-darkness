/**
* @file		ConvertProvider.cpp
* @brief	コンバータを提供する
* @author	S.OIKAWA
* @date		2017.04.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ConvertProvider.h"
#include"AABBToOBB.h"
#include"AABBToSphere.h"
#include"OBBToAABB.h"
#include"OBBToSphere.h"
#include"SphereToAABB.h"
#include"SphereToOBB.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{
			namespace Converter
			{

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				ConvertProvider::ConvertProvider()
				{
					m_Converters.push_back(new AABBToOBB);
					m_Converters.push_back(new AABBToSphere);
					m_Converters.push_back(new OBBToAABB);
					m_Converters.push_back(new OBBToSphere);
					m_Converters.push_back(new SphereToAABB);
					m_Converters.push_back(new SphereToOBB);
				}

				//-----------------------------------------------------------
				// dtor
				//-----------------------------------------------------------
				ConvertProvider::~ConvertProvider()
				{
					for (auto _ : m_Converters)
					{
						SAFE_DELETE(_);
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------