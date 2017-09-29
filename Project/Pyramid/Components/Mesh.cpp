/**
* @file		Mesh.h
* @brief	Fbx�̃��b�V���̋@�\��񋟂���R���|�[�l���g
* @author	S.OIKAWA
* @date		2016.08.01
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Mesh.h"
#include"../Rendering/RendringPriority.h"
#include"../Common/WorldVolume.h"
#include"../Rendering/Graphics.h"
#include"../Rendering/Detail/OptimizationRender.h"
#include"../Rendering/Detail/Optimize/LODSwitcher.h"
#include"../Rendering/Detail/Optimize/MLRCPublisher.h"
#include"../Rendering/Detail/Optimize/JudgmentSameSpaceOfFrustum.h"
#include"../Rendering/Materials/MeshMaterial.h"
#include"../Resource/Model/FbxFile.h"
#include"../Resource/API/Model.h"
#include"../Resource/ResourceManager.h"

#include"../Components/Transform.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

using namespace Pyramid::Resources::Model;
using namespace Pyramid::Rendering::Materials;
namespace Pyramid
{
	namespace Components
	{
		/// <summary>
		/// ctor
		/// </summary>
		Mesh::Mesh(std::string _path):
			m_Render(m_Materials)
		{
			auto& mgr = Resources::ResourceManager::Instantiate();
			m_Model = mgr.OnLoad<FbxFile>(_path);

			_ASSERT_EXPR(m_Model.spResourceFile->Meshs.size(),_T(L"���b�V���ǂݍ��ݎ��s"));
			
		}

		/// <summary>
		/// �R�s�[�p�̃R���X�g���N�^
		/// </summary>
		Mesh::Mesh() :
			m_Render( m_Materials)
		{
			//static_assert(true, "Used Copy Ctor Of Mesh");
		}

		Mesh::~Mesh()
		{

			for (auto& _ : m_Materials)
			{
				SAFE_DELETE(_);
			}

			___DEBUG_DEFINE
			(
				SAFE_DELETE(m_pAABBRender);
			)
		}

		/// <summary>
		/// ���\�[�X������
		/// </summary>
		void Mesh::Init(Common::Sp<Transform>& _transforom)
		{
			m_Model.Init();
			m_Model.SetMatrix(_transforom->MatWorld);

			MaterialLoad();
			//���\�[�X�����S�Ɋm�ۂ���Ă���R�}���h�𔭍s����
			m_Render.Init(
				m_Model.spResourceFile,
				_transforom,
				Rendering::RendringPriority::Geometry);


			___DEBUG_CALL(AdditionalInitOfDebug(_transforom));
		}


		/// <summary>
		/// �X�V.
		/// </summary>
		void Mesh::Updata()
		{
			m_Render.OptimizerUpdate();
		}

		/// <summary>
		/// �����_�����O
		/// </summary>
		void Mesh::PreDraw()
		{

		}


		//-----------------------------------------------------------
		// MaterialLoad
		//-----------------------------------------------------------
		void Mesh::MaterialLoad()
		{
			auto size = m_Model.spResourceFile->Meshs.size();
			m_Materials.reserve(size);
			m_Materials.resize(size);

			auto it = m_Model.spResourceFile->Meshs.begin();

			for (auto& _ : m_Materials)
			{
				_ = 
					new Rendering::Materials::MeshMaterial(
					*(*it)->Materials[0]);//Material�͕K��1�ȏ�L��
			}


		}

	___DEBUG_DEFINE(

		///// <summary>
		///// �����_�����O�̈��`�悷��
		///// </summary>
		void Mesh::AdditionalInitOfDebug(Common::Sp<Transform>& _transforom)
		{

			m_pAABBRender = new Rendering::ComponentRender::AABBRender();

			m_pAABBRender->Init(
				m_Render.RenderVolume,
				_transforom,
				Rendering::RendringPriority::Geometry + 1);

		}

		/// <summary>
		/// �����_�����O�̈��`�悷��
		/// </summary>
		void Mesh::AdditionalUpdataOfDebug()
		{
			m_pAABBRender->RenderVolume = m_Render.RenderVolume;
		}
		)
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------