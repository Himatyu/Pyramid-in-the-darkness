/**
* @file		OBBAndOBB.h
* @brief	OBBëŒOBBÇÃè’ìÀîªíË
* @author	S.OIKAWA
* @date		2017.03.05
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IDiagramCollider.h"
#include"../Common/Diagram/OBB.h"
#include"../Defines.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			namespace Collider
			{
				/// <summary>
				/// OBBëŒOBBÇÃè’ìÀîªíË
				/// </summary>
				class OBBAndOBB :
					public IDiagramCollider<Common::Diagram::OBB, Common::Diagram::OBB>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					OBBAndOBB() = default;
					~OBBAndOBB() = default;

					OBBAndOBB(const OBBAndOBB&) = default;
					OBBAndOBB(OBBAndOBB&&) = default;

					OBBAndOBB& operator=(const OBBAndOBB&) = default;
					OBBAndOBB& operator=(OBBAndOBB&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// è’ìÀ
					/// </summary>
					Utility::Nullable<ResultPair>
						IsCollision(IVolume * _pOBB1, IVolume * _pOBB2) override;
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------