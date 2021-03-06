/**
* @file		ICommonBehavior.h
* @brief	Pyramidにおける共通動作
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
		/// Pyramidにおける共通動作
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
			/// 初期化.
			/// </summary>
			virtual void Init() = 0;

			/// <summary>
			/// 終了処理.
			/// </summary>
			virtual void Finit() = 0;

			/// <summary>
			/// 更新.
			/// </summary>
			virtual void Updata() = 0;

			/// <summary>
			/// 描画.
			/// </summary>
			virtual void PreDraw() = 0;

#pragma endregion
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------