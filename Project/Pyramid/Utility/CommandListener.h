/**
* @file		CommandListener.h
* @brief	�R�}���h�̓o�^�A�폜��񋟂���
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include"SafetyIterate.h"
#pragma endregion

#pragma region define
	//-----------------------------------------------------------
	// define
	//-----------------------------------------------------------
#pragma endregion

namespace Utility
{
	class ICommand;
	/// <summary>
	/// �R�}���h��o�^����
	/// </summary>
	class CommandListener
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		CommandListener() = default;
		virtual ~CommandListener() = default;

		CommandListener(const CommandListener&) = default;
		CommandListener(CommandListener&&) = default;

		CommandListener& operator=(const CommandListener&) = default;
		CommandListener& operator=(CommandListener&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// �R�}���h�ǉ�.
		/// </summary>
		void AddCommand(ICommand*);

		/// <summary>
		/// �R�}���h�폜.
		/// </summary>
		void RemoveCommand(ICommand*);

		/// <summary>
		/// �R�}���h���m�肷��
		/// �󂢂��R�}���h������ꍇ�C���f�b�N�X�������̂Œ���
		/// </summary>
		void CommandApply();
#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_REF(m_CommandList.Vector, CommandList, std::vector<ICommand*>);
#pragma endregion

	protected:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		SafetyIterate<ICommand*>		m_CommandList;
#pragma endregion
	};

}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------