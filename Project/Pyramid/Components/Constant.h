/**
* @file		Constant.h
* @brief	Components�̒萔���`����
* @author	S.OIKAWA
* @date		2016.11.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<windef.h>
#include<functional>
#include<string>
#include<array>
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
		namespace Detail
		{
			class Particle;
		}
		class Constant final
		{
		public:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
			/// <summary>
			/// �J�����X�V�̃��C��ID
			/// </summary>
			const static UINT CameraMTUpdataLineID;

			/// <summary>
			/// �g�����X�t�H�[���X�V�̃��C��ID
			/// </summary>
			const static UINT TransformMTUpdataLineID;

			/// <summary>
			/// �p�[�e�B�N���X�V�̃��C��ID
			/// </summary>
			const static UINT ParticleMTUpdataLineID;

			/// <summary>
			/// �p�[�e�B�N���̕`��D��x
			/// </summary>
			const static UINT ParticleMTRenderingPriority;

			/// <summary>
			/// �V�F�[�_�ɓn��Difuse�̃p�����^��
			/// </summary>
			const static std::string LightDifuseParameter;

			/// <summary>
			/// �V�F�[�_�ɓn��Direct�̃p�����^��
			/// </summary>
			const static std::string LightDirectParameter;

			/// <summary>
			/// �p�[�e�B�N���Ŏg�p����d��
			/// </summary>
			const static Utility::Vector3 ParticleGravity;

			/// <summary>
			/// �W���̒ǉ�������
			/// </summary>
			const static std::function<void(Detail::Particle&)> DefaultAdditionalInitialize;

			/// <summary>
			/// �W���̒ǉ��X�V
			/// </summary>
			const static std::function<void(Detail::Particle&)> DefaultAdditionalUpdata;

			/// <summary>
			/// �f�o�b�N���Ɏg�p���錩���ڏՓ˃��f���̐F
			/// </summary>
			const static std::array<std::array<float,4>, 12> EmissiveOfDebugCollisinVolume;

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------