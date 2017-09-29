/**
* @file		Optimizer.h
* @brief	�œK�����s��
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
				/// IOptimizer�����������œK�����s��
				/// ��̃N���X���s�����e��F�m���Ȃ�
				/// ���ۂ̏����̓e���v���[�g�ɂĎw�肷��
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
					/// �������Ăяo��
					/// </summary>
					void CallInit();

					/// <summary>
					/// �X�V�Ăяo��
					/// </summary>
					void CallUpdate();

					/// <summary>
					/// �œK���Ăяo��
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