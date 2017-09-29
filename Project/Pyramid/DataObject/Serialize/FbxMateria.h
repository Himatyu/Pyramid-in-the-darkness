/**
* @file		FbxMaterial.h
* @brief	FBX�̃}�e���A���V���A���C�Y���
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

//-----------------------------------------------------------
// icnlude 
//-----------------------------------------------------------
#include"ISerializable.h"
#include"ColorChannel.h"
#include"../FileDataObjectChild.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/FbxMateria.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Serialize
	{
		/// <summary>
		/// FBX�̃}�e���A���f�[�^�I�u�W�F�N�g.
		/// ����P�̂ł͈��킸�AFbx�̃V���A���C�Y�̈�Ƃ��Ďg�p���邱��.
		/// </summary>
		class FbxMaterial final :
			public DTO::DTOAccess<DTO::FbxMaterial>,
			public FileDataObjectChild,
			public ISerializable
		{
		public:
			FbxMaterial(std::fstream& _parentStream);
			~FbxMaterial();

			/// <summary>
			/// �J���[�`�����l���̏����o��.
			/// ���łɊJ�����X�g���[���ɑ΂��ď�������.
			/// �J���Ă��Ȃ��ꍇ�������Ȃ�.
			/// </summary>
			void Serialize() override;

		private:
			ColorChannel m_Emissive;
			ColorChannel m_Ambient;
			ColorChannel m_Diffuse;
			ColorChannel m_Specular;
			ColorChannel m_Bump;
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
