/**
* @file		SetMaterial.cpp
* @brief	�f�t�H���g�}�e���A�����f�o�C�X�ɑ��M����
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SetMaterial.h"
#include"../../Graphics.h"
#include"../../Materials/Material.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			namespace Default
			{
				//-----------------------------------------------------------
				// Execute
				//-----------------------------------------------------------
				void SetMaterial::Execute()
				{
					auto pDevice = Graphics::Instantiate().Device;
					Rendering::Materials::Material::SetDefaultMaterial();
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
