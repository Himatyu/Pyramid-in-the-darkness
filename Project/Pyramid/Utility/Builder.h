/**
* @file		Builder.h
* @brief	CompleteConstructor�ȃr���h�̃x�[�X�@�\���
* @author	S.OIKAWA
* @date		2016.10.26
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	/// CompleteConstructor�ȃr���h�̃x�[�X
	/// </summary>
	template<class Result, class ...Param>
	class Builder
	{
	public:
		//-----------------------------------------------------------
		// defaluts
		//-----------------------------------------------------------
		Builder() = default;
		~Builder() = default;

		Builder(const Builder&) = default;
		Builder(Builder&&) = default;

		Builder& operator=(const Builder&) = default;
		Builder& operator=(Builder&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// �r���h
		/// </summary>
		virtual void Build(Param&& ...) = 0;

		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_REF_R_ONLY(m_Built, Built, Nullable<Result>);

		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
	protected:
		Nullable<Result>	m_Built;
	};
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------