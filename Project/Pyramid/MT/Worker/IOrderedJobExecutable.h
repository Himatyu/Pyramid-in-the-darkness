/**
* @file		IOrderedJobExecutable.h
* @brief	�W���u���s�@�\�̃C���^�[�t�F�[�X
* @author	S.OIKAWA
* @date		2016.11.23
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
	namespace MT
	{
		namespace Worker
		{
			/// <summary>
			/// OrderedJobExcuter�Ŏ��s�����Job�̃C���^�[�t�F�[�X
			/// OrderedJobExcuter�Ŕj�����邽��class
			/// </summary>
			class IOrderedJobExecutable
			{
			public:
				IOrderedJobExecutable() = default;
				virtual ~IOrderedJobExecutable() = default;

				IOrderedJobExecutable(const IOrderedJobExecutable&) = default;
				IOrderedJobExecutable(IOrderedJobExecutable&&) = default;

				IOrderedJobExecutable& operator=(const IOrderedJobExecutable&) = default;
				IOrderedJobExecutable& operator=(IOrderedJobExecutable&&) = default;
				
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void Execution() = 0;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------