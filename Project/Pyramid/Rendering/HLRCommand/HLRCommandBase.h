/**
* @file		HLRCommandBase.h
* @brief	HLRコマンドの基本機能を提供
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICommand.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	class CommandExecutor;
}
namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			/// <summary>
			/// データの保持と変更機能を提供.
			/// </summary>
			template<class PushDataType>
			class HLRCommandBase : 
				public ::Utility::ICommand
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				HLRCommandBase(PushDataType, ::Utility::CommandExecutor*);
				virtual ~HLRCommandBase() = default;

				HLRCommandBase(const HLRCommandBase&) = default;
				HLRCommandBase(HLRCommandBase&&) = default;

				HLRCommandBase& operator=(const HLRCommandBase&) = default;
				HLRCommandBase& operator=(HLRCommandBase&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_PushData, PushData, PushDataType);

#pragma endregion
			protected:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				PushDataType				m_PushData;
				::Utility::CommandExecutor*	m_pOwner;
#pragma endregion
			};
#include"HLRCommandBase.inl"
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------