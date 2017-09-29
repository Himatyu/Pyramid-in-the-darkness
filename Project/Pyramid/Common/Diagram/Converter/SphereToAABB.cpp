/**
* @file		SphereAndAABB.cpp
* @brief	Sphere‚ðAABB‚É•ÏŠ·‚·‚é
* @author	S.OIKAWA
* @date		2017.05.01
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SphereToAABB.h"
#include"../AABB.h"
#include"../Sphere.h"
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
				SphereToAABB::SphereToAABB()
				{
					TypeApply<Sphere,AABB>();
				}

				//-----------------------------------------------------------
				// Convert
				//-----------------------------------------------------------
				std::shared_ptr<IDiagram> SphereToAABB::Convert(IDiagram * _pSphere)
				{
					auto pSphere = _pSphere->CastTo<Sphere*>();
					auto pAabb = std::make_shared<AABB>();

					auto half = Utility::Vector3::once * pSphere->R;

					pAabb->Max = pSphere->Center + half;
					pAabb->Min = pSphere->Center - half;

					return pAabb;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------