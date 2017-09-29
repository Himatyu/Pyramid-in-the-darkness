/**
* @file		DirectXTextureFile.h
* @brief	DirectX�e�N�X�`��������
* @author	S.OIKAWA
* @date		2016.08.21
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<d3d9.h>
#include<d3dx9.h>
#include "ITextureFile.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Texture
		{
			/// <summary>
			/// DirectX�`���̃e�N�X�`��������.
			/// </summary>
			class DirectXTextureFile :
				public ITextureFile
			{
			public:

				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				DirectXTextureFile() = default;
				virtual ~DirectXTextureFile();

				DirectXTextureFile(const DirectXTextureFile&) = default;
				DirectXTextureFile(DirectXTextureFile&&) = default;

				DirectXTextureFile&operator=(const DirectXTextureFile&) = default;
				DirectXTextureFile&operator=(DirectXTextureFile&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �t�@�C���ǂݍ���.
				/// </summary>
				/// <param name="_path">�t�@�C���p�X</param>
				/// <returns>�ǂݍ��ݐ�������</returns>
				void Read(std::string _path) override;

				/// <summary>
				/// ����j������.
				/// </summary>
				void Discard() override;

				//-----------------------------------------------------------
				// operator
				//-----------------------------------------------------------
				PROPERTY(m_ImageInfo, Info, D3DXIMAGE_INFO);
				PROPERTY(m_ColorKey, ColorKey, D3DCOLOR);
				PROPERTY(m_Usage, Usage, DWORD);
				PROPERTY(m_Filter, Filter, DWORD);
				PROPERTY(m_MipFilter, MipFilter, DWORD);
				PROPERTY(m_MipLevels, MipLevels, UINT);
				PROPERTY(m_Format, Format, D3DFORMAT);
				PROPERTY(m_Pool, Pool, D3DPOOL);
				PROPERTY(m_pTexture, pTexture, IDirect3DTexture9*);

			protected:
				//-----------------------------------------------------------
				// Val
				//-----------------------------------------------------------
				D3DXIMAGE_INFO		m_ImageInfo;					//�摜���
				D3DCOLOR			m_ColorKey = 0;					//���S�ɓ����ɂ���F
				DWORD				m_Usage = 0;					//�e�N�X�`���̐����E�m�ۂ��郁�����̏ꏊ
				DWORD				m_Filter = D3DX_DEFAULT;		//�C���[�W�̃t�B���^�����O���@
				DWORD				m_MipFilter = D3DX_DEFAULT;		//�~�b�v�}�b�v�ɑ΂��čs����t�B���^�����O�@
				UINT				m_MipLevels = 1;				//�~�b�v�}�b�v���x��
				D3DFORMAT			m_Format = D3DFMT_A8R8G8B8;		//�s�N�Z���t�H�[�}�b�g
				D3DPOOL				m_Pool = D3DPOOL_DEFAULT;		//�e�N�X�`�����i�[���郁�����̈ʒu�ƊǗ�
				IDirect3DTexture9*	m_pTexture = nullptr;			//�e�N�X�`���|�C���^	

			};
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------