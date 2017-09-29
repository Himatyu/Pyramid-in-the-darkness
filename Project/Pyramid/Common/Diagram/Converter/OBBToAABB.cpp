/**
* @file		OBBToAABB.cpp
* @brief	OBB‚ðAABB‚É•ÏŠ·‚·‚é
* @author	S.OIKAWA
* @date		2017.05.01
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OBBToAABB.h"
#include"../AABB.h"
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
				OBBToAABB::OBBToAABB()
				{
					TypeApply<OBB,AABB>();
				}

				//-----------------------------------------------------------
				// Convert
				//-----------------------------------------------------------
				std::shared_ptr<IDiagram> OBBToAABB::Convert(IDiagram * _pOBB)
				{
					auto pAabb = std::make_shared<AABB>();
					auto pObb = _pOBB->CastTo<OBB*>();

					auto halfX =
						pObb->CalculateHalfProjectLengthOnSeparatAxis(
							Utility::Vector3::rigth);

					auto halfY =
						pObb->CalculateHalfProjectLengthOnSeparatAxis(
							Utility::Vector3::up);

					auto halfZ =
						pObb->CalculateHalfProjectLengthOnSeparatAxis(
							Utility::Vector3::forward);
					
					auto half = Utility::Vector3(halfX, halfY, halfZ);
					pAabb->Max = pObb->Center + half;
					pAabb->Min = pObb->Center - half;

					return pAabb;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------