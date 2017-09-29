/**
* @file		Optimizer.h
* @brief	最適化を行う
* @author	S.OIKAWA
* @date		2017.03.31
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"InterfaceCoordinator.h"
#include"IOptimizer.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				class Context;
			}
		}
	}
}
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
				/// IOptimizerを実装した最適化を行う
				/// 具体クラスが行う内容を認知しない
				/// 実際の処理はテンプレートにて指定する
				/// </summary>
				template<class ...Args>
				class Optimizer :
					public Utility::InterfaceCoordinator
					<
					IOptimizer,Args...
					>
				{
				public:
					using Utility::InterfaceCoordinator
						<
						IOptimizer,	Args...
						>::InterfaceCoordinator;
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Optimizer() = default;
					~Optimizer() = default;

					Optimizer(const Optimizer&) = default;
					Optimizer(Optimizer&&) = default;

					Optimizer& operator=(const Optimizer&) = default;
					Optimizer& operator=(Optimizer&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
				protected:
					/// <summary>
					/// 初期化呼び出し
					/// </summary>
					void CallInit();

					/// <summary>
					/// 更新呼び出し
					/// </summary>
					void CallUpdate();

					/// <summary>
					/// 最適化呼び出し
					/// </summary>
					void CallOptimize(const Context&);

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
#include"Optimizer.inl"
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------