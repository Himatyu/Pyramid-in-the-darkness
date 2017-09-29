/**
* @file		Range.h
* @brief
* @author
* @date
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


namespace Utility
{
	/// <summary>
	/// ”ÍˆÍ‚ð’è‹`‚·‚é
	/// </summary>
	template<class Ty>
	class Range
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		Range(Ty, Ty);
		~Range() = default;

		Range(const Range&) = default;
		Range(Range&&) = default;

		Range& operator=(const Range&) = default;
		Range& operator=(Range&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// ”ÍˆÍ“à‚ÉŠÜ‚Ü‚ê‚Ä‚é
		/// </summary>
		const bool IsContains(Ty _val);

		/// <summary>
		/// 
		/// </summary>
		bool operator ==(const Range&);

		/// <summary>
		/// 
		/// </summary>
		bool operator !=(const Range&);


#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
		PROPERTY_R_ONLY(m_Min, Min, Ty);
		PROPERTY_R_ONLY(m_Max, Max, Ty);
#pragma endregion

#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
	
		static float Epsilon;
	private:
		Ty m_Min, m_Max;
#pragma endregion
	};
#include"Range.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------