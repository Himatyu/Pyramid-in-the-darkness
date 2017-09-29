/**
* @file		IDiagram.h
* @brief	図形共通処理
* @author	S.OIKAWA
* @date		2017.04.06
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Defines.h"
#include"ICastable.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	class Vector3;
}
namespace Pyramid
{
	namespace Components
	{
		class Transform;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{
			/// <summary>
			/// 図形共通処理
			/// </summary>
			class IDiagram : 
				public Utility::ICastable
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				IDiagram() = default;
				virtual ~IDiagram() = default;

				IDiagram(const IDiagram&) = default;
				IDiagram(IDiagram&&) = default;

				IDiagram& operator=(const IDiagram&) = default;
				IDiagram& operator=(IDiagram&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void ReflectionOfTransfrom(Common::Sp<Components::Transform>&) = 0;
				virtual void MoveTo(const Utility::Vector3&) {};
				virtual void ScaleTo(const Utility::Vector3&) {};
				virtual void RotateTo(const Utility::Vector3&) {};//TODO クオータニオン化
				virtual void Initialize() = 0;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion

#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------