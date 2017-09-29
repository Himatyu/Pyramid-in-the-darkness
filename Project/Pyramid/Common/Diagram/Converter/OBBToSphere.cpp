/**
* @file		OBBAndSphere.cpp
* @brief	OBB‚ðSphere‚É•ÏŠ·‚·‚é
* @author	S.OIKAWA
* @date		2017.05.01
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OBBToSphere.h"
#include"../Sphere.h"
#include"../OBB.h"
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
				OBBToSphere::OBBToSphere()
				{
					TypeApply<OBB,Sphere>();
				}

				//-----------------------------------------------------------
				// OBBAndSphere
				//-----------------------------------------------------------
				std::shared_ptr<IDiagram> OBBToSphere::Convert(IDiagram * _pOBB)
				{
					auto pSphere = std::make_shared<Sphere>();
					auto pObb = _pOBB->CastTo<OBB*>();

					pSphere->Center = pObb->Center;
					pSphere->R = max(pObb->Half.X, max(pObb->Half.Y, pObb->Half.Z));

					return pSphere;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------