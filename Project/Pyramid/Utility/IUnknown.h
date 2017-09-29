/**
* @file		Unknown.h
* @brief	void*�Ƃ��ĐU�镑���I�u�W�F�N�g�𖾎��I�Ɏ���
* @author	S.OIKAWA
* @date		2017.06.02
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Utility
{
	/// <summary>
	/// void*�Ƃ��ĐU�镑���I�u�W�F�N�g�𖾎��I�Ɏ���
	/// </summary>
	__interface IUnknown
	{

	};

	/// <summary>
	/// void*�Ƃ��ĐU�镑���I�u�W�F�N�g�𖾎��I�Ɏ���
	/// �f�X�g���N�^������
	/// </summary>
	class Unknown
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		Unknown() = default;
		virtual ~Unknown() = default;

		Unknown(const Unknown&) = default;
		Unknown(Unknown&&) = default;

		Unknown& operator=(const Unknown&) = default;
		Unknown& operator=(Unknown&&) = default;
#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------