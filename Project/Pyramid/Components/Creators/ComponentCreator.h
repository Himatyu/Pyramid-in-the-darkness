/**
* @file		ComponentCreator.h
* @brief	コンポーネントの生成関数を提供する
* @author	S.OIKAWA
* @date		2016.02.19
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Creator.h"
#include"../Component.h"
#include<memory>

//-----------------------------------------------------------
// deffine
//-----------------------------------------------------------
namespace Pyramid
{
	namespace GameObject
	{
		class Object;
	}
}

namespace Pyramid
{
	namespace Components
	{
		namespace Creators
		{

			/// <summary>
			///コンポーネントのクリエイタ
			///コンポーネント又はその子を生成
			/// </summary> 
			///<typeparam name="Child">生成コンポーネント型</typeparam>
			///<typeparam name="Parent">所得型スマポ</typeparam>
			template<class Child,
				class Parent = std::shared_ptr<Component>>
				class ComponentCreator final :
				public Utility::Creator<Parent>
			{
			public:
				//-----------------------------------------------------------
				// ctor.dtor
				//-----------------------------------------------------------	
				ComponentCreator() = default;
				virtual ~ComponentCreator() = default;

				//-----------------------------------------------------------
				//  default
				//-----------------------------------------------------------

				ComponentCreator(const ComponentCreator&) = default;
				ComponentCreator(ComponentCreator&&) = default;

				ComponentCreator&operator=(const ComponentCreator&) = default;
				ComponentCreator&operator=(ComponentCreator&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
					/// <summary>Childを生成しスマポParentで返す</summary>
					///<returns>親又生成したコンポーネントのスマポ</returns>
				Parent Create() override;

				//-----------------------------------------------------------
				// Val
				//-----------------------------------------------------------
					/// <summary>
					/// 型情報
					/// </summary>
				using ValueType = Child;
			};
#include"ComponentCreator.inl"

		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

