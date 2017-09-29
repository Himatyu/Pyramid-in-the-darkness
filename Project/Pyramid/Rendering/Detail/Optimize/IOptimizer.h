/**
* @file		IOptimizer.h
* @brief	�œK�����ۃN���X
* @author	S.OIKAWA
* @date		2017.03.30
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
				/// �œK�����ۃN���X
				/// �K�v�ȏ������͋�̃N���X�̃R���X�g���N�^�ōs������
				/// </summary>
				class IOptimizer
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					IOptimizer() = default;
					virtual ~IOptimizer() = default;

					IOptimizer(const IOptimizer&) = default;
					IOptimizer(IOptimizer&&) = default;

					IOptimizer& operator=(const IOptimizer&) = default;
					IOptimizer& operator=(IOptimizer&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					///
					/// </summary>
					virtual void Init() = 0 {};

					/// <summary>
					/// 
					/// </summary>
					virtual void Update() = 0 {};

					/// <summary>
					/// �œK�����s��
					/// </summary>
					virtual void RunOptimize(const Context&) = 0 {};
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
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------