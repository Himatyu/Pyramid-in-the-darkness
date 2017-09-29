/**
* @file		ICommonBehavior.h
* @brief	PyramidÇ…Ç®ÇØÇÈã§í ìÆçÏ
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
		/// PyramidÇ…Ç®ÇØÇÈã§í ìÆçÏ
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
			/// èâä˙âª.
			/// </summary>
			virtual void Init() = 0;

			/// <summary>
			/// èIóπèàóù.
			/// </summary>
			virtual void Finit() = 0;

			/// <summary>
			/// çXêV.
			/// </summary>
			virtual void Updata() = 0;

			/// <summary>
			/// ï`âÊ.
			/// </summary>
			virtual void PreDraw() = 0;

#pragma endregion
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------