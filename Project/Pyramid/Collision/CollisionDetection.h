/**
* @file		CollisionDetection.h
* @brief	�Փ˔���̎��s���@���`����
* @author	S.OIKAWA
* @date		2017.04.29
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		/// <summary>
		/// �Փ˔���̐��x
		/// </summary>
		enum class Detection : int
		{
			/// <summary>
			/// ���݈ʒu�Փ˔�����s���B
			/// �g���l�����O�͑΍􂵂Ȃ�
			/// </summary>
			Discontinuity = 0, 

			/// <summary>
			/// Swept Volume Test
			/// �Փː}�`�̃t���[���ԃ{�����[���𐶐���������s��
			/// ����̍ہA�t���[���Ԃ̂ǂ��ŏՓ˂����������Z���Ȃ�
			/// �ՓˑΏۂ�Object�ƌ��݂̃g�����X�t�H�[�����C�x���g�ɗ���
			/// ����덷�̓t���[���Ԃ̊g�k�Ɖ�]�ʂɔ�Ⴕ�đ傫���Ȃ�
			/// ����̍ۂɉ�]�E�g�k�𖳎��ł��邪�덷���傫���Ȃ�
			/// </summary>
			SVT,

			/// <summary>
			/// �\���̂̃J�E���g
			/// �ݒ肷���CollisionProvider�ŃA�T�[�g
			/// </summary>
			Count,
		};
		
		/// <summary>
		/// �Փ˔���̐��x�p�����[�^
		/// </summary>
		class CollisionDetection final
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			CollisionDetection();
			~CollisionDetection() = default;

			CollisionDetection(const CollisionDetection&);
			CollisionDetection(CollisionDetection&&);

			CollisionDetection& operator=(const CollisionDetection&);
			CollisionDetection& operator=(CollisionDetection&&) ;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			
#pragma endregion

#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_REF(m_Detection, Value, Detection);
			PROPERTY_REF(m_IsIgnoreRotateThenSVT,	IsIgnoreRotateThenSVT,	bool);
			PROPERTY_REF(m_IsIgnoreScaleThenSVT,	IsIgnoreScaleThenSVT,	bool);

#pragma endregion

#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			Detection	m_Detection;

			bool		m_IsIgnoreRotateThenSVT;	
			bool		m_IsIgnoreScaleThenSVT;
#pragma endregion
		};

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------