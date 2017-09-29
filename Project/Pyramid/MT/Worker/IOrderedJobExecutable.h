/**
* @file		IOrderedJobExecutable.h
* @brief	ジョブ実行機能のインターフェース
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
			/// OrderedJobExcuterで実行されるJobのインターフェース
			/// OrderedJobExcuterで破棄するためclass
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