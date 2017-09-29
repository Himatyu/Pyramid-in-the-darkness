/**
* @file		MLRCPublisher.h
* @brief	MLRCを持ち発行機能を継承して提供する
* @author	S.OIKAWA
* @date		2016.11.25
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IMLRCPublishable.h"
#include"../Rendering/Detail/Optimize/MLRC.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Pyramid
{
	namespace MT
	{
		namespace Order
		{
			/// <summary>
			/// MLRCを持ち発行機能を継承して提供する
			/// </summary>
			class MLRCPublisher final :
				public IMLRCPublishable
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				MLRCPublisher() = default;
				~MLRCPublisher() = default;

				MLRCPublisher(const MLRCPublisher&) = default;
				MLRCPublisher(MLRCPublisher&&) = default;

				MLRCPublisher& operator=(const MLRCPublisher&) = default;
				MLRCPublisher& operator=(MLRCPublisher&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual Rendering::Detail::Optimize::MLRC* PublishMLRC() override = 0;
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
				Rendering::Detail::Optimize::MLRC			m_MLRC;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------