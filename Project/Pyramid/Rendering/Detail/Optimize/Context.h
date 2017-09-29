/**
* @file		Context.h
* @brief	ç≈ìKâªéûÇ…ìnÇ≥ÇÍÇÈèÓïÒ
* @author	S.OIKAWA
* @date		2017.03.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Continuity.h"
#include"Vector3.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				/// <summary>
				/// ç≈ìKâªéûÇ…ìnÇ≥ÇÍÇÈèÓïÒ
				/// </summary>
				class Context
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Context(const Continuity, Utility::Vector3&);
					Context() = delete;
					~Context() = default;

					Context(const Context&) = default;
					Context(Context&&) = default;

					Context& operator=(const Context&) = default;
					Context& operator=(Context&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
					PROPERTY(m_ContinuityAttribute, ContinuityAttribute, Continuity);
					PROPERTY(m_RefCameraPos, RefCameraPos,Utility::Vector3);
#pragma endregion

				private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
					Continuity			m_ContinuityAttribute;
					Utility::Vector3&	m_RefCameraPos;
#pragma endregion
				};
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------