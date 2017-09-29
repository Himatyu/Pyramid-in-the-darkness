/**
* @file		DirectXDelete.h
* @brief	DirectX�o�b�t�@�̃��\�[�X�J��
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once

//-----------------------------------------------------------
// inlcude 
//-----------------------------------------------------------
#include"../Rendering/Graphics.h"
#include<d3dx9.h>

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
			/// DirectX�ň����o�b�t�@���J������|���V�[
			/// </summary>
			template<class>
			struct DirectXBufferDaleta
			{
				template<class Ty>
				void Delete(Ty _p)
				{
					SAFE_RELEASE(_p);
				}
			};
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------