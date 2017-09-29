/**
* @file		CommandFinalizer.h
* @brief	�R�}���h�̍œK�����s�������_�����O���X�g���m�肳����
* @author	S.OIKAWA
* @date		2017.01.27
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include"../IRenderable.h"
#include"../Optimize/IOptimize.h"
#include"../OptimizationRender.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		class Viewer;
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
				/// �R�}���h�̍œK�����s�������_�����O���X�g���m�肳����
				/// MT�ɓ����\��
				/// </summary>
				class CommandFinalizer
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					CommandFinalizer(Viewer**);
					~CommandFinalizer() = default;

					CommandFinalizer(const CommandFinalizer&) = default;
					CommandFinalizer(CommandFinalizer&&) = default;

					CommandFinalizer& operator=(const CommandFinalizer&) = default;
					CommandFinalizer& operator=(CommandFinalizer&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					std::vector<IRenderable*>
						Run(const std::list<OptimizationRender*>& _published);

#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------

#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					Viewer**		m_ppCurrent;
#pragma endregion
				};
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------