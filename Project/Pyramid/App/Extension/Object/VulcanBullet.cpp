/**
* @file		VulcanBullet.cpp
* @brief	バレットオブジェクト
* @author	S.OIKAWA
* @date		2017.02.15
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"VulcanBullet.h"
#include"../App/Extension/Component/VulcanBulletControler.h"
#include"../App/Extension/Component/VulcanBulletInvalidater.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Rendering::HLRCommand::Stage;
using CmdStage = HLRCPipelineStage;
namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Object
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				VulcanBullet::VulcanBullet(Blueprint::Level* _pLevel):
					Actor(_pLevel)
				{
				}
				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void VulcanBullet::Init()
				{
					m_pControler = AddComponent<Component::VulcanBulletControler>();				
					m_pInvalidater = AddComponent<Component::VulcanBulletInvalidater>();
					m_pMesh = 
						AddComponent<Components::Mesh>("Assets/Model/Bullet.bm");
					m_pMesh->Init(spTransform);
					auto& resourceMeshs = m_pMesh->Model.spResourceFile->Meshs;

					for (auto& _ : resourceMeshs)
					{
						auto& mat = _->Materials[0];
						mat->Emissive.Value = { 1.0f,1.0f,1.0f,1.0f };
						mat->Ambient.Value = { 0,0,0,0 };
						mat->Diffuse.Value = { 1,1,1,1 };
					}
					
					//Test
					m_pMesh->MeshRender.RenderID = 100;
					auto ignoreHead = 
						Utility::Range<CmdStage>(CmdStage::EndScene, CmdStage::EndScene);
					auto ignoreTail = 
						Utility::Range<CmdStage>(CmdStage::BeginScene, CmdStage::SetIndex);
					m_pMesh->MeshRender.IgnoreRangeHead = ignoreHead;
					m_pMesh->MeshRender.IgnoreRangeTail = ignoreTail;

					auto& ignoreList =
						m_pMesh->MeshRender.IgnoreRangeMiddleRangeList;
					ignoreList.push_back(ignoreHead);
					ignoreList.push_back(ignoreTail);


					m_pMesh->IsRendering = false;
					isActive = false;

					___DEBUG_DEFINE( m_pMesh->IsRenderingAABB = false;)
				}

				//-----------------------------------------------------------
				// Updata
				//-----------------------------------------------------------
				void VulcanBullet::Updata()
				{
					Object::Updata();
				}

				//-----------------------------------------------------------
				// OnFire
				//-----------------------------------------------------------
				void VulcanBullet::OnFire(
					Utility::Vector3& _PopPos,
					std::shared_ptr<Components::Transform> _Player)
				{
					isActive = true;
					m_pMesh->IsRendering = true;

					m_pControler->Init(_PopPos, _Player->Forward);
					spTransform->Rotation = _Player->Rotation;
					m_pInvalidater->Init();

					___DEBUG_DEFINE(m_pMesh->IsRenderingAABB = true;)
				}

				//-----------------------------------------------------------
				// OnInvalidate
				//-----------------------------------------------------------
				void VulcanBullet::OnInvalidate()
				{
					m_pMesh->IsRendering = false;
					isActive = false;
					m_pInvalidater->OnInvalidate();

					___DEBUG_DEFINE(m_pMesh->IsRenderingAABB = false;)
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------