/**
* @file		Viewer.cpp
* @brief	レンダリングに必要なカメラ側の情報をまとめる
* @author	S.OIKAWA
* @date		2016.12.20
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Viewer.h"
#include"Target\RenderingTexture.h"
#include"Graphics.h"
#include"../Components/Camera.h"
#include"../Common/SpaceDivide/OctreeRegistrableObject.h"
#include"../Rendering/Detail/Optimize/JudgmentSameSpaceOfFrustum.h"
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Viewer::Viewer():
			m_ViewFrustum(*this)
		{
			D3DXMatrixIdentity(&m_View);
			D3DXMatrixIdentity(&m_Proj);
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		Viewer::~Viewer()
		{
		}

		//-----------------------------------------------------------
		// SetRenderTarget
		//-----------------------------------------------------------
		void Viewer::SetRenderTarget()
		{
			if (!m_pRenderingTexture)
			{
				Graphics::Instantiate().BackScreen.SetTarget();
				return;
			}
			m_pRenderingTexture->SetTarget();
		}

		//-----------------------------------------------------------
		// RiseRenderTarget
		//-----------------------------------------------------------
		void Viewer::RiseRenderTarget()
		{
			if (!m_pRenderingTexture)
			{
				return;
			}
			Graphics::Instantiate().BackScreen.SetTarget();
		}

		//-----------------------------------------------------------
		// CalculateClipMatrix
		//-----------------------------------------------------------
		void Viewer::CalculateFrustum()
		{
			m_ViewFrustum.PlanesUpdate();	
			m_ViewFrustum.CompositionPointUpdate();
		}

		//-----------------------------------------------------------
		// GetObjectOfSameSpace
		//-----------------------------------------------------------
		std::list<Rendering::Detail::Optimize::MLRCPublisher*>
			Viewer::GetObjectOfSameSpace()
		{
			std::list<Rendering::Detail::Optimize::MLRCPublisher*> list;
			m_ViewFrustum.ExcludesOtherTypeObjectInSameSpace();

			for (auto _ : m_ViewFrustum.SameSpaceList)
			{				
				auto pJudge = 
					_->CastTo<Detail::Optimize::JudgmentSameSpaceOfFrustum*>();
				
				Utility::Estd::combineList(list, pJudge->MLRCPublisherList);
			}

			list.unique();
			return list;
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

