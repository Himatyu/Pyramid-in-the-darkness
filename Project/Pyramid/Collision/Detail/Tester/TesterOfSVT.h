/**
* @file		TesterOfSVT.h
* @brief	SVTÇä‹Çﬁè’ìÀîªíËÇçsÇ§
* @author	S.OIKAWA
* @date		2017.04.29
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ITester.h"
#include"../Collider/OBBAndOBB.h"
#include"../Common/Diagram/OBB.h"
#include"../Defines.h"
#include<vector>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			class ICollidee;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			namespace Tester
			{
				/// <summary>
				/// SVTÇä‹Çﬁè’ìÀîªíËÇçsÇ§
				/// </summary>
				class TesterOfSVT final :
					public ITester
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					using ITester::ITester;

					TesterOfSVT() = delete;
					~TesterOfSVT() = default;

					TesterOfSVT(const TesterOfSVT&) = default;
					TesterOfSVT(TesterOfSVT&&) = default;

					TesterOfSVT& operator=(const TesterOfSVT&) = default;
					TesterOfSVT& operator=(TesterOfSVT&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					Utility::Nullable<EventPair> Run(ICollidee*, ICollidee*)override;

				private:
					std::vector<Common::Diagram::OBB> CreateSVs(ICollidee*);
					Utility::Nullable<EventPair> TestOfCollision(
						std::vector<Common::Diagram::OBB>&, 
						std::vector<Common::Diagram::OBB>&,
						ICollidee*, ICollidee*);

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion
				private:
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