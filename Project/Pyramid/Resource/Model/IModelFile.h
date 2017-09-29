/**
* @file		IModelFile.h
* @brief	���f���t�@�C�����������ׂ��@�\�̃C���^�[�t�F�[�X���
* @author	S.OIKAWA
* @date		2016.11.6
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3dx9.h>
#include"../Common/Diagram/AABB.h"
#include"../IResource.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Model
		{
			/// <summary>
			/// ���f���t�@�C�����������ׂ��@�\�Ǝ��ׂ��ϐ�
			/// </summary>
			class IModelFile :
				public IResource
			{
			public:
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				IModelFile() = default;
				virtual ~IModelFile()= default;

				IModelFile(const IModelFile&) = default;
				IModelFile(IModelFile&&) = default;

				IModelFile& operator=(const IModelFile&) = default;
				IModelFile& operator=(IModelFile&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void InitializeUseDaveice() = 0;
				virtual void SetMatrix(D3DXMATRIX&) = 0;

				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_Volume, Volume, Common::Diagram::AABB);

				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			protected:
				Common::Diagram::AABB		m_Volume;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
