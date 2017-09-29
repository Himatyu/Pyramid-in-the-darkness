/**
* @file		IOptimize.h
* @brief	�œK���C���^�[�t�F�[�X
* @author	S.OIKAWA
* @date		2017.03.28
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
				/// �œK���C���^�[�t�F�[�X
				/// </summary>
				class IOptimize
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					IOptimize() = default;
					virtual ~IOptimize() = default;

					IOptimize(const IOptimize&) = default;
					IOptimize(IOptimize&&) = default;

					IOptimize& operator=(const IOptimize&) = default;
					IOptimize& operator=(IOptimize&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					virtual void PrepareToOptimize() = 0 {};			//�t���[�����Ƃ̌Ăяo���O��
					virtual void Optimize(const Context&) = 0 {};
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY(m_RenderID, RenderID,unsigned);
#pragma endregion
				protected:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					unsigned	m_RenderID;
#pragma endregion
				};
			}
		}
	}
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------