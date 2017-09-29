/**
* @file		IEventHook.h
* @brief	�I�u�W�F�N�g�E�R���|�[�l���g�̃C�x���g��
* @author	S.OIKAWA
* @date		2016.09.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICommonBehavior.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion
namespace Pyramid
{
	namespace GameObject
	{
		/// <summary>
		/// �I�u�W�F�N�g�E�R���|�[�l���g�̒ǉ��C�x���g.
		/// </summary>
		class IEventHook :
			public ICommonBehavior
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			IEventHook() = default;
			~IEventHook() = default;

			IEventHook(const IEventHook&) = default;
			IEventHook(IEventHook&&) = default;

			IEventHook& operator=(const IEventHook&) = default;
			IEventHook& operator=(IEventHook&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// �A�b�v�f�[�g�̑O�ɃR�[�������.
			/// </summary>
			virtual void FastUpdata() = 0;

			/// <summary>
			/// �A�b�v�f�[�g�̌�ɃR�[�������.
			/// </summary>
			virtual void LateUpdata() = 0;

#pragma endregion
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------