/**
	  * @file		ISerializable.h
	  * @brief		�V���A���C�Y����C���^�[�t�F�[�X��񋟂���
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */

#pragma once

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace DataObject
{
	namespace POCO
	{
		/// <summary>
		/// �������݂̃C���^�[�t�F�[�X.
		/// </summary>
		__interface ISerializable
		{
			void Serialize();
		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------