/**
* @file		ScriptableObject.h
* @brief	固定値データをもつ
* @author	S.OIKAWA
* @date		2017.5.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IDataObjectFile.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Pyramid
{
	namespace Resources
	{
		namespace DataObject
		{
			/// <summary>
			/// 固定値データをもつ
			/// </summary>
			template<class _Ty>
			class ScriptableObject :
				public IDataObjectFile
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ScriptableObject();
				~ScriptableObject() = default;

				ScriptableObject(const ScriptableObject&) = default;
				ScriptableObject(ScriptableObject&&) = default;

				ScriptableObject& operator=(const ScriptableObject&) = default;
				ScriptableObject& operator=(ScriptableObject&&) = default;
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
				PROPERTY_REF(m_Data, Data, _Ty);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				_Ty			m_Data;
#pragma endregion
			};
#include"ScriptableObject.inl"
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------