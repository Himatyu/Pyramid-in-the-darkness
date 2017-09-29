/**
* @file		Interface.h
* @brief	���ۃv���o�C�_�[
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Provider
			{
				/// <summary>
				///���ۃv���o�C�_�[
				/// </summary>
				class Interface
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Interface() = default;
					virtual ~Interface() = default;

					Interface(const Interface&) = default;
					Interface(Interface&&) = default;

					Interface& operator=(const Interface&) = default;
					Interface& operator=(Interface&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					
					/// <summary>
					/// �`��
					/// </summary>
					virtual void Rendering() = 0;
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