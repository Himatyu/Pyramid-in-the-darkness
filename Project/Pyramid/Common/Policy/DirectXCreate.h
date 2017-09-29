/**
* @file		DirectXCreate.h
* @brief	DirectX�Ő����Ɏg�p����|���V�[
* @author	S.OIKAWA
* @date		2016.11.10
*/

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<d3dx9.h>
#include"../Rendering/Graphics.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		namespace Policy
		{
			/// <summary>
			/// ���_�o�b�t�@�𐶐�����|���V�[
			/// </summary>
			template<class>
			struct DirectXVertexBufferCreate
			{
				void Create(
					UINT _lenght,
					DWORD _usage,
					DWORD _fvf,
					D3DPOOL _pool,
					IDirect3DVertexBuffer9** _ppVertexBuffer,
					HANDLE* _pSharedHandle)
				{
					auto& pDevice = Rendering::Graphics::Instantiate().Device;

					pDevice->CreateVertexBuffer(
						_lenght,
						_usage,
						_fvf,
						_pool,
						_ppVertexBuffer,
						_pSharedHandle
						);
				}
			};

			/// <summary>
			/// �C���f�b�N�X�o�b�t�@�𐶐�����|���V�[
			/// </summary>
			template<class>
			struct DirectXIndexBufferCreate
			{
				void Create(
					UINT _length,
					DWORD _usage,
					D3DFORMAT _format,
					D3DPOOL _pool,
					IDirect3DIndexBuffer9** _ppIndexBuffer,
					HANDLE* _pSharedHandle)
				{
					auto& pDevice = Rendering::Graphics::Instantiate().Device;

					pDevice->CreateIndexBuffer(
						_length,
						_usage,
						_format,
						_pool,
						_ppIndexBuffer,
						_pSharedHandle
						);
				}
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------