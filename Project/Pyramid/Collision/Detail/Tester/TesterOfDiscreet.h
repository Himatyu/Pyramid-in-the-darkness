/**
* @file		TesterOfDiscreet.h
* @brief	トンネリング対策を行わない衝突判定
* @author	S.OIKAWA
* @date		2017.04.29
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ITester.h"
#include"../../IVolume.h"
#include"../ColliderManager.h"
#include"../FindResult.h"
#include"../Common/Defines.h"
#include"../Defines.h"
#include<vector>
#include<list>
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
				/// トンネリング対策を行わない衝突判定
				/// </summary>
				class TesterOfDiscreet final:
					public ITester
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					using ITester::ITester;

					TesterOfDiscreet() = delete;
					~TesterOfDiscreet() = default;

					TesterOfDiscreet(const TesterOfDiscreet&) = default;
					TesterOfDiscreet(TesterOfDiscreet&&) = default;

					TesterOfDiscreet& operator=(const TesterOfDiscreet&) = default;
					TesterOfDiscreet& operator=(TesterOfDiscreet&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					Utility::Nullable<EventPair> Run(ICollidee*, ICollidee*)override;

				private:
					Utility::Nullable<EventPair>  TestOfRegistedCollidee(
						std::list<FindResult::ForLog>&);

					Utility::Nullable<EventPair>  TestOfUnRegistedCollidee(
						std::vector<Common::Sp<IVolume>>&,
						std::vector<Common::Sp<IVolume>>&);
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