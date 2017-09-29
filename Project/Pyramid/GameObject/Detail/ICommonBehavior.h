/**
* @file		ICommonBehavior.h
* @brief	Pyramid�ɂ����鋤�ʓ���
* @author	S.OIKAWA
* @date		2016.09.19
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
	namespace GameObject
	{
		/// <summary>
		/// Pyramid�ɂ����鋤�ʓ���
		/// </summary>
		class ICommonBehavior
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			ICommonBehavior() = default;
			~ICommonBehavior() = default;

			ICommonBehavior(const ICommonBehavior&) = default;
			ICommonBehavior(ICommonBehavior&&) = default;

			ICommonBehavior& operator=(const ICommonBehavior&) = default;
			ICommonBehavior& operator=(ICommonBehavior&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// ������.
			/// </summary>
			virtual void Init() = 0;

			/// <summary>
			/// �I������.
			/// </summary>
			virtual void Finit() = 0;

			/// <summary>
			/// �X�V.
			/// </summary>
			virtual void Updata() = 0;

			/// <summary>
			/// �`��.
			/// </summary>
			virtual void PreDraw() = 0;

#pragma endregion
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------