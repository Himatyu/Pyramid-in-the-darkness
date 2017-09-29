/**
* @file		FbxMaterial.h
* @brief	FBX�̃}�e���A���f�[�^�I�u�W�F�N�g���
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

//-----------------------------------------------------------
// icnlude 
//-----------------------------------------------------------
#include"IDeserializable.h"
#include"DOColorChannel.h"
#include"FileDateObject.h"
#include"../Macro.h"
#include<vector>
#include<fstream>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

class FbxAndBMInterconverter;
namespace DataObject
{
	namespace DTO
	{
		class FbxMaterial
		{
		public:
			PROPERTY_REF(mEmissive, Emissive,	ColorChannel);
			PROPERTY_REF(mAmbient,	Ambient,	ColorChannel);
			PROPERTY_REF(mDiffuse,	Diffuse,	ColorChannel);
			PROPERTY_REF(mSpecular, Specular,	ColorChannel);
			PROPERTY_REF(mBump,		Bump,		ColorChannel);

			PROPERTY_REF(mShinness,		Shinness,		float);
			PROPERTY_REF(mTransparency, Transparency,	float);
			PROPERTY_REF(mReflectivity, Reflectivity,	float);

		private:
			ColorChannel mEmissive;
			ColorChannel mAmbient;
			ColorChannel mDiffuse;
			ColorChannel mSpecular;
			ColorChannel mBump;

			float mShinness = 1.0;
			float mTransparency = 1.0;
			float mReflectivity = 0.0;
		};
	}

	namespace POCO
	{
		namespace Serialize
		{
			/// <summary>
			/// FBX�̃}�e���A���f�[�^�I�u�W�F�N�g.
			/// ����P�̂ł͈��킸�AFbx�̃V���A���C�Y�̈�Ƃ��Ďg�p���邱��.
			/// </summary>
			class FbxMaterial :
				public FileDateObjectChild,
				public ISerializable
			{
				friend class FbxAndBMInterconverter;
			public:
				FbxMaterial(std::fstream& _parentStream);
				~FbxMaterial();

				/// <summary>
				/// �J���[�`�����l���̏����o��.
				/// ���łɊJ�����X�g���[���ɑ΂��ď�������.
				/// �J���Ă��Ȃ��ꍇ�������Ȃ�.
				/// </summary>
				void Serialize() override;

				PROPERTY_REF(m_Material, Material, DTO::FbxMaterial);

			private:
				DTO::FbxMaterial m_Material;
				
				ColorChannel mEmissive;
				ColorChannel mAmbient;
				ColorChannel mDiffuse;
				ColorChannel mSpecular;
				ColorChannel mBump;
			};
		}

		namespace Deserialize
		{
			/// <summary>
			/// FBX�̃}�e���A���f�[�^�I�u�W�F�N�g.
			/// ����P�̂ł͈��킸�AFbx�̃V���A���C�Y�̈�Ƃ��Ďg�p���邱��.
			/// </summary>
			class FbxMaterial :
				public FileDateObjectChild,
				public IDeserializable
			{
				friend class FbxAndBMInterconverter;
			public:
				FbxMaterial(std::fstream& _parentStream);
				~FbxMaterial();

				/// <summary>
				/// �J���[�`�����l���̏����o��.
				/// ���łɊJ�����X�g���[���ɑ΂��ď�������.
				/// �J���Ă��Ȃ��ꍇ�������Ȃ�.
				/// </summary>
				void Deserialize() override;

				PROPERTY_REF(m_Material, Material, DTO::FbxMaterial);

			private:
				DTO::FbxMaterial m_Material;

				ColorChannel mEmissive;
				ColorChannel mAmbient;
				ColorChannel mDiffuse;
				ColorChannel mSpecular;
				ColorChannel mBump;

			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
