/**
* @file		Model.h
* @brief	���f�����\�[�X��API
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
			/// ���f�����\�[�X��API
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
				/// �o�b�t�@�������Ȃǂ̒x���������s��.
				/// </summary>
				void Init();

				/// <summary>
				/// ���[���h�s����Z�b�g����
				/// </summary>
				void SetMatrix(D3DXMATRIX&);

				/// <summary>
				/// ���X�g����.
				/// </summary>
				void OnLost() override;

				/// <summary>
				/// ���A����.
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
