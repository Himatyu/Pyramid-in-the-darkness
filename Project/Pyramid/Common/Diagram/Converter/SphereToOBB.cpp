/**
* @file		SphereToOBB.cpp
* @brief	Sphere‚ðOBB‚É•ÏŠ·‚·‚é
* @author	S.OIKAWA
* @date		2017.05.01
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SphereToOBB.h"
#include"../OBB.h"
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
				SphereToOBB::SphereToOBB()
				{
					TypeApply<Sphere,OBB>();
				}

				//-----------------------------------------------------------
				// Convert
				//-----------------------------------------------------------
				std::shared_ptr<IDiagram> SphereToOBB::Convert(IDiagram * _pSphere)
				{
					auto pSphere = _pSphere->CastTo<Sphere*>();
					auto pObb = std::make_shared<OBB>();

					pObb->Center = pSphere->Center;
					pObb->Half = Utility::Vector3::once * pSphere->R;

					return pObb;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------