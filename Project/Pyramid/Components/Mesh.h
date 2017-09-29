/**
* @file		Mesh.h
* @brief	Fbx�̃��b�V���̋@�\��񋟂���R���|�[�l���g
* @author	S.OIKAWA
* @date		2016.08.01
*/

#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Components/Component.h"
#include"../MT/Order/TaskOrder.h"
#include"../Resource/Model/FbxFile.h"
#include"../Resource/API/Model.h"
#include"../Resource/ResourceType.h"
#include"../Rendering/ComponentRender/FbxRender.h"
#include"../Rendering/ComponentRender/AABBRender.h"
#include"../Rendering/Materials/MeshMaterial.h"

#include<vector>
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		using MaterialList =
			std::vector<Rendering::Materials::MeshMaterial*>;
		/// <summary>
		/// Fbx�̃��b�V���̋@�\��񋟂���R���|�[�l���g
		/// �����Ȃ��ModelAPI�Ƀ��f������񋟂���@�\���K�v������
		/// Fbx�̃}�e���A����InnerMesh�ɑ΂��Ĉ�����s��Ȃ�
		/// </summary>
		class Mesh :
			public Component,
			private MT::Order::TaskOrder<Mesh>
		{
		public:
			//-----------------------------------------------------------
			// ctor 
			//-----------------------------------------------------------
			Mesh(std::string _path);

			//-----------------------------------------------------------
			// default 
			//-----------------------------------------------------------
			Mesh();	//�����p�̃R���X�g���N�^
			~Mesh();

			Mesh(const Mesh&) = default;
			Mesh(Mesh&&) = default;

			Mesh& operator=(const Mesh&) = default;
			Mesh& operator=(Mesh&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// ������.�f�o�C�X���g�p���ăf�[�^���쐬����
			/// </summary>
			void Init(Common::Sp<Transform>& _transforom);

			/// <summary>
			/// �X�V.
			/// </summary>
			void Updata() override ;

			/// <summary>
			/// �����_�����O�̎��O����
			/// </summary>
			virtual void PreDraw() override;

		private:			

			void MaterialLoad();

			/// <summary>
			/// �����_�����O�̈������������
			/// </summary>
			___DEBUG_DEFINE(void AdditionalInitOfDebug(Common::Sp<Transform>& _transforom));

			/// <summary>
			/// �����_�����O�̈��`�悷��
			/// </summary>
			___DEBUG_DEFINE(void AdditionalUpdataOfDebug() override);

		public:
			//-----------------------------------------------------------
			// Property
			//-----------------------------------------------------------
			PROPERTY_REF_R_ONLY(m_Model, Model, Resources::ModelFBX);
			PROPERTY_REF_R_ONLY(m_Render, MeshRender, Rendering::ComponentRender::FbxRender);
			PROPERTY_REF_R_ONLY(m_Materials, Materials, MaterialList);
			PROPERTY_REF(m_Render.IsCommandPublish, IsRendering, bool);

			___DEBUG_DEFINE(PROPERTY_REF(m_pAABBRender->IsCommandPublish, IsRenderingAABB, bool));
		protected:
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			Resources::ModelFBX								m_Model;
			Rendering::ComponentRender::FbxRender			m_Render;
			MaterialList									m_Materials;
			
			___DEBUG_DEFINE(Rendering::ComponentRender::AABBRender*			m_pAABBRender);

		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------