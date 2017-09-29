/**
* @file		Constant.h
* @brief	Common�̒萔���`����
* @author	S.OIKAWA
* @date		2016.11.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<windef.h>
#include<string>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Common
	{		
		class Constant final
		{
		public:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
			/// <summary>
			/// �^�C���T�[�o�p�̍X�VID
			/// </summary>
			const static UINT TimerServerMTUpdataLineID;

			/// <summary>
			///	Updata�^�X�N�̃O���[�v��
			/// </summary>
			static const std::string MTUpdataGrupName;

			/// <summary>
			/// Draw�^�X�N�̃O���[�v��
			/// </summary>
			static const std::string MTDrawGrupName;

			/// <summary>
			///	�����؂̍ő啪�����x���B
			/// �^�I��9
			/// </summary>
			static const unsigned OctreeMaxLevel;

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------