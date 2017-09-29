/**
* @file		Panel.h
* @brief	�p�l�����\�����钸�_����ێ�
* @author	S.OIKAWA
* @date		2016.12.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"
#include"Quad.h"
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
			namespace StaticResource
			{
				/// <summary>
				/// �p�l�����\�����钸�_����ێ�
				/// �p�C�v���C����}�e���A���͑��ɔC����
				/// </summary>
				class Panel :
					public Quad,
					public Utility::Singleton<Panel>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Panel();
					~Panel() = default;

					Panel(const Panel&) = default;
					Panel(Panel&&) = default;

					Panel& operator=(const Panel&) = default;
					Panel& operator=(Panel&&) = default;
#pragma endregion
				private:
#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					void CreateBuffer();
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