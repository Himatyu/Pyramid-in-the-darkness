/**
* @file		IRenderable.h
* @brief	�����_�����O�\�ȃC���^�[�t�F�[�X��
* @author	S.OIKAWA
* @date		2016.11.4
*/
#pragma once

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			/// <summary>
			/// �����_�����O�\�ɂ���C���^�[�t�F�[�X
			/// </summary>
			__interface IRenderable
			{
				void PrepareToRendering();
				void Rendering();
			};
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------