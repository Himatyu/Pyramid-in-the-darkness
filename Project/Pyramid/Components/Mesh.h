/**
* @file		Mesh.h
* @brief	Fbxのメッシュの機能を提供するコンポーネント
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
		/// Fbxのメッシュの機能を提供するコンポーネント
		/// そうなるとModelAPIにモデル情報を提供する機能が必要がある
		/// FbxのマテリアルはInnerMeshに対して一つしか行わない
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
			Mesh();	//複製用のコンストラクタ
			~Mesh();

			Mesh(const Mesh&) = default;
			Mesh(Mesh&&) = default;

			Mesh& operator=(const Mesh&) = default;
			Mesh& operator=(Mesh&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// 初期化.デバイスを使用してデータを作成する
			/// </summary>
			void Init(Common::Sp<Transform>& _transforom);

			/// <summary>
			/// 更新.
			/// </summary>
			void Updata() override ;

			/// <summary>
			/// レンダリングの事前処理
			/// </summary>
			virtual void PreDraw() override;

		private:			

			void MaterialLoad();

			/// <summary>
			/// レンダリング領域を初期化する
			/// </summary>
			___DEBUG_DEFINE(void AdditionalInitOfDebug(Common::Sp<Transform>& _transforom));

			/// <summary>
			/// レンダリング領域を描画する
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