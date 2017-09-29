/**
* @file		MorphableMesh.h
* @brief	モーフィング可能なモデルを提供
* @author	S.OIKAWA
* @date		2016.12.16
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Mesh.h"
#include"../Resource/Model/FbxFile.h"
#include"../Rendering/Buffer.h"
#include"../Components/Transform.h"
#include<vector>
#include<d3d9.h>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Components
	{	
		using MorphBuffer = std::vector<Rendering::DirectXVertexBuffer>;
		using MorphVertex = std::vector<std::vector<D3DXVECTOR3>>;

		/// <summary>
		/// モーフィング可能なモデルを提供
		/// </summary>
		class MorphableMesh:
			public Mesh
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			MorphableMesh() = default;
			~MorphableMesh() = default;

			MorphableMesh(std::string _path);

			MorphableMesh(const MorphableMesh&) = default;
			MorphableMesh(MorphableMesh&&) = default;

			MorphableMesh& operator=(const MorphableMesh&) = default;
			MorphableMesh& operator=(MorphableMesh&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			/// <summary>
			/// 初期化.デバイスを使用してデータを作成する
			/// </summary>
			void Init(Common::Sp<Transform>& _transforom);

			/// <summary>
			/// バッファ更新
			/// </summary>
			void PreDraw() override;

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
			PROPERTY_REF(m_MorphOffset, MorphOffset, MorphVertex);
			PROPERTY_REF(m_Progress, Progress,float);
#pragma endregion
		private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			float m_Time = 0;
			float m_RestTime = 0;
			float m_Progress = 0.0f;
			bool  m_IsLerping = false;
			MorphVertex m_MorphOffset;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------