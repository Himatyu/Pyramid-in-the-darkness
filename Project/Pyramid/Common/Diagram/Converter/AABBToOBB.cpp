/**
* @file		AABBAndOBB.cpp
* @brief	AABB‚ðOBB‚É•ÏŠ·‚·‚é
* @author	S.OIKAWA
* @date		2017.05.01
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"AABBToOBB.h"
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
				AABBToOBB::AABBToOBB()
				{
					TypeApply<AABB,OBB>();
				}


				//-----------------------------------------------------------
				// Convert
				//-----------------------------------------------------------
				std::shared_ptr<IDiagram> AABBToOBB::Convert(IDiagram * _pAABB)
				{
					auto pObb = std::make_shared<OBB>();
					auto pAabb = _pAABB->CastTo<AABB*>();

					pObb->Center = pAabb->CalculateOfCenter();
					pObb->Half = pAabb->Max - pObb->Center;
					return pObb;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------