/**
* @file		Constant.h
* @brief	Blueprint�̒萔���`����
* @author	S.OIKAWA
* @date		2016.11.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<Windows.h>
#include<tchar.h>
#include<stdlib.h>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Blueprint
	{
		class Constant final
		{
		public:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

			/// <summary>
			/// �N���X�E�v���Z�X��
			/// </summary>
			static const TCHAR ClassName[];

			/// <summary>
			/// �v���V�[�W���v���p�e�B
			/// </summary>
			static const TCHAR ClientProc[];

			static const unsigned			DivideSpaceLevel;

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------