/**
* @file		RenderProvider.h
* @brief	�����_�����O�i���or�e�N�X�`���j���w�肵�Ȃ���S��
* @author	S.OIKAWA
* @date		2016.11.1
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"
#include"Detail/Provider/Interface.h"
#include"Detail/Provider/WolrdRendering.h"
#include"Detail/Provider/UIRendering.h"
#include<vector>
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
		/// <summary>
		/// �����_�����O���s���@�\���.
		/// </summary>
		class RenderProvider final :
			public ::Utility::Singleton<RenderProvider>
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			RenderProvider();
			~RenderProvider();

			RenderProvider(const RenderProvider&) = default;
			RenderProvider(RenderProvider&&) = default;

			RenderProvider& operator=(const RenderProvider&) = default;
			RenderProvider& operator=(RenderProvider&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// �����_�����O���s��
			/// </summary>
			void Rendering();

		private:
			Detail::Provider::WolrdRendering&	GetInstanceOfWolrd();
			Detail::Provider::UIRendering&		GetInstanceOfUI();
#pragma endregion

		public:
#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_REF_R_ONLY(GetInstanceOfWolrd(), Wolrd, Detail::Provider::WolrdRendering);
			PROPERTY_REF_R_ONLY(GetInstanceOfUI(), UI, Detail::Provider::UIRendering);
#pragma endregion
		private:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			std::vector<Detail::Provider::Interface*> m_Providers;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------