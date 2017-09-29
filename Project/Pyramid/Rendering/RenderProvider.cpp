/**
* @file		RenderProvider.cpp
* @brief	�����_�����O�i���or�e�N�X�`���j���w�肵�Ȃ���S��
* @author	S.OIKAWA
* @date		2016.11.1
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"RenderProvider.h"
#include"Graphics.h"
#include"Detail/Provider/UIRendering.h"
#include"Detail/Provider/WolrdRendering.h"
#include"Detail/Provider/Interface.h"
#include<d3dx9.h>

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

using namespace std;
using namespace Pyramid;
using namespace Pyramid::Rendering;
using namespace Pyramid::Rendering::Detail::Provider;

namespace Pyramid
{
	namespace Rendering
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		RenderProvider::RenderProvider()
		{
			m_Providers.push_back(static_cast<Interface*>(new WolrdRendering));
			m_Providers.push_back(static_cast<Interface*>(new UIRendering));
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		RenderProvider::~RenderProvider()
		{
			for (auto _ : m_Providers)
			{
				SAFE_DELETE(_);
			}
		}

		//-----------------------------------------------------------
		// Rendering
		//-----------------------------------------------------------
		void RenderProvider::Rendering()
		{
			for (auto _ : m_Providers)
			{
				_->Rendering();
			}

			auto& graphic = Graphics::Instantiate();
			auto pDevice = graphic.Device;
			// �o�b�N�o�b�t�@�ɕ`�悵�����e��\��
			if (FAILED(pDevice->Present(NULL, NULL, NULL, NULL)))
			{
				//TODO �Ή�
				auto presntParams = Graphics::Instantiate().PresentParameters;
				pDevice->Reset(&presntParams);
			}
		}

		//-----------------------------------------------------------
		// GetInstanceOfWolrd
		//-----------------------------------------------------------
		Detail::Provider::WolrdRendering & RenderProvider::GetInstanceOfWolrd()
		{
			return *static_cast<WolrdRendering*>(m_Providers[0]);
		}

		//-----------------------------------------------------------
		// GetInstanceOfUI
		//-----------------------------------------------------------
		Detail::Provider::UIRendering & RenderProvider::GetInstanceOfUI()
		{
			return *static_cast<UIRendering*>(m_Providers[1]);
		}

	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------