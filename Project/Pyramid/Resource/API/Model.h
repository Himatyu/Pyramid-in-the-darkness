/**
* @file		Model.h
* @brief	モデルリソースのAPI
* @author	S.OIKAWA
* @date		2016.09.02
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../API/LostResourceAPI.h"
#include"../Common/Diagram/AABB.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace API
		{
			/// <summary>
			/// モデルリソースのAPI
			/// </summary>
			template <class Type>
			class Model final :
				public LostResourceAPI<Type>
			{
			public:
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Model() = default;
				~Model() = default;

				Model(const Model&) = default;
				Model(Model&&) = default;

				Model& operator=(const Model&) = default;
				Model& operator=(Model&&) = default;
				//-----------------------------------------------------------
				// function 
				//-----------------------------------------------------------

				/// <summary>
				/// バッファ初期化などの遅延処理を行う.
				/// </summary>
				void Init();

				/// <summary>
				/// ワールド行列をセットする
				/// </summary>
				void SetMatrix(D3DXMATRIX&);

				/// <summary>
				/// ロスト処理.
				/// </summary>
				void OnLost() override;

				/// <summary>
				/// 復帰処理.
				/// </summary>
				void Recover() override;


				//-----------------------------------------------------------
				// operator
				//-----------------------------------------------------------
				void operator=(std::shared_ptr<Type> _sp);

				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_Volume, Volume, Common::Diagram::AABB);

			private:
				//-----------------------------------------------------------
				// var
				//-----------------------------------------------------------

				Common::Diagram::AABB		m_Volume;
			};
#include"Model.inl"
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
